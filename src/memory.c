#include "memory.h"
#include "common.h"
#include "gpu.h"
#include "gb.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

CPU *hackCpu = NULL;

extern byte gpuPalette;
byte *ROM, BIOS[0x100], WRAM[0x3E00], VRAM[0x2000], CRAM[0x2000], ZRAM[0x80], IO[0x80];
byte INT_ENABLE;

// The OAM actually only uses 160 bytes, and the rest
// should return 0, but we'll ignore that for now. Possible bug.
byte OAM[256];

void memoryInit(const char *romPath) {
	readBytes("bios.bin", BIOS, 256);

	// For now, just load the first two banks.
	long size = sizeFile(romPath);
	ROM = (byte*)malloc(size);
	readBytes(romPath, ROM, size);
	printf("ROM passed is %ld bytes.\n", size);
}

long memClock = 0;
long counterClock = 0;
long dividerClock = 0;

// Used to hold the settings of the Counter timer.
struct CounterControl {
	union {
		struct {
			byte speed:2;
			byte running:1;
			byte unused:5;
		};

		byte _data;
	};
};

void memoryStep(long cycles, struct CPU *cpu) {
	hackCpu = cpu;

	memClock += cycles;
	counterClock += cycles;
	dividerClock += cycles;
	bool timerInterrupt = false;

	// Advance divider timer
	while (dividerClock >= 16384) {
		dividerClock -= 16384;
		IO[0x04]++;
		timerInterrupt = true;
	}

	// Advance counter timer.
	struct CounterControl ctrl;
	ctrl._data = IO[0x07];

	if (ctrl.running) {
		long frequencies[4] = {4096, 262144, 65536, 16384};
		long frequency = frequencies[ctrl.speed];
		byte *counter = IO + 0x05;

		while (counterClock >= frequency) {
			counterClock -= frequency;
			(*counter)++;

			if (*counter == 0) {
				// Reset to modulo if overflowed.
				*counter = IO[0x06];

				timerInterrupt = true;
			}
		}
	}

	if (timerInterrupt) {
		gbRequestInterrupt(cpu, TIMER_INTERRUPT_MASK);
	}
}

bool isBiosEnabled() {
	// Don't call readByte, since readByte calls us :l
	return (IO[0xFF50 - 0xFF00] & 0x01) == 0;
}

void writeByte(word address, byte b) {

	switch (address & 0xF000) {
		case 0x0000:
			if (address < 0x100 && isBiosEnabled())
				BIOS[address] = b;
			else
				ROM[address] = b;
			break;

		case 0x1000: case 0x2000: case 0x3000: case 0x4000:
		case 0x5000: case 0x6000: case 0x7000:
			// We can't write to ROM so this is interfacing with the MBC.
			printf("Write of %02x to %04x (ROM) failed\n", b, address);
			exit(1);
			break;

		case 0x8000: case 0x9000:
			VRAM[address - 0x8000] = b;
			gpuUpdateVRAM(address, b);
			break;

		case 0xA000: case 0xB000:
			CRAM[address - 0xA000] = b;
			break;

		case 0xC000: case 0xD000: case 0xE000:
			WRAM[address - 0xC000] = b;
			break;

		case 0xF000:
			if (address < 0xFE00)
				WRAM[address - 0xF000] = b;
			else if (address < 0xFEA0)
				OAM[address - 0xFE00] = b;
			else if (address < 0xFF00) {
				printf("Write of %02x to %04x failed (Unusable RAM!)\n", b, address);
				return; //< Unusable RAM
			} else if (address < 0xFF80) { //< IO
				if (address == 0xFF84)
					IO[address - 0xFF00] = 0; //< DIV register can only be reset.
				else
					IO[address - 0xFF00] = b;
			} else if (address < 0xFFFF) { //< Zero page
				ZRAM[address - 0xFF80] = b;
			} else {
				INT_ENABLE = b; //< Interrupt enable flag
			}
			break;
	}

	if (hackCpu) {
//		printf("[%04x] (%04x) = %02x\n", hackCpu->PC, address, b);
	}
}

void writeWord(word address, word w) {
	writeByte(address + 1, w & 0xFF);
	writeByte(address, w >> 8);
}

byte readByte(word address) {
	// Hack for until we implement the GPU.
	if (address == 0xFF44) return 0x90;

	// Map an array to memory from lower to upper (including upper)
	#define MEMORY_REGION(name, lower, upper) \
		if (address <= ( upper )) return (name)[address - ( lower )];

	{
		// This list should be in ascending address order!!!
		// (and make sure EVERY region is properly defined in size and adjacent memory.)

		// We haven't defined restart/interrupt vectors and cartridge header area!
		if (isBiosEnabled()) {
			MEMORY_REGION(BIOS, 0, 0x00FF); 			//< BIOS
		}

		MEMORY_REGION(ROM, 0, 0x3FFF);          //< ROM bank 0
		MEMORY_REGION(ROM, 0, 0x7FFF);          //< ROM (switchable banks)

		MEMORY_REGION(VRAM, 0x8000, 0x97FF);    //< Character (Video) RAM
		MEMORY_REGION(VRAM, 0x9800, 0x9BFF) 		//< BG Map Data 1
		MEMORY_REGION(VRAM, 0x9C00, 0x9FFF) 		//< BG Map Data 2

		MEMORY_REGION(CRAM, 0xA000, 0xBFFF);    //< Cartridge RAM (if available)
		MEMORY_REGION(WRAM, 0xC000, 0xCFFF);    //< Internal RAM bank 0
		MEMORY_REGION(WRAM, 0xD000, 0xDFFF);    //< Internal RAM bank (1 - 7, switchable, Color Gameboy only)
		MEMORY_REGION(WRAM, 0xE000, 0xFDFF); 	  //< Echo RAM (don't use, but it's working RAM mirrored)

		MEMORY_REGION(OAM, 0xFE00, 0xFE9F); 		//< Object Attribute Memory
		if (address < 0xFEFF) { return 0; }			//< Unusable RAM (0xFEA0 - 0xFEFF)
		if (address == 0xFF47) return 0; 				//< IO Background Palette, Read only.
		MEMORY_REGION(IO, 0xFF00, 0xFF7F); 			//< Hardware IO Registers
		MEMORY_REGION(ZRAM, 0xFF80, 0xFFFE); 		//< Zero page
		return INT_ENABLE; 											//< Interrupt enable flag IE at 0xFFFF
	}

	// Done!
	#undef MEMORY_REGION
}

word readWord(word address) {
	byte upper = readByte(address + 1);
	byte lower = readByte(address);
	return makeWord(upper, lower);
}