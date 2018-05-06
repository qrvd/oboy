#ifndef GB_H
#define GB_H

#include "common.h"
#include <stdbool.h>

#define VBLANK_INTERRUPT_MASK 	((byte)0x01)
#define LCD_INTERRUPT_MASK 			((byte)0x02)
#define TIMER_INTERRUPT_MASK 		((byte)0x04)
#define SERIAL_INTERRUPT_MASK 	((byte)0x08)
#define JOYPAD_INTERRUPT_MASK 	((byte)0x10)

struct CPU {
	word PC, SP;
	long clock;
	bool halted, interrupts;

	union {
		struct {

			// MSB -> LSB order
			struct {
				byte _: 4;
				bool Z: 1;
				bool S: 1;
				bool H: 1;
				bool C: 1;
			} F;

			byte A;
		};

		word AF;
	};

	#define pair(left, right) union { struct { byte right, left; }; word left##right; }
		pair(B, C);
		pair(D, E);
		pair(H, L);
	#undef pair
} __attribute__((packed));

struct Instruction {
	const char *mnemonic;
	void (*execute)(CPU *cpu, byte d8, ibyte r8, word d16);
	byte length, duration;
};

long gbStep(CPU *cpu);
long gbDebugStep(struct CPU *cpu);
void gbRequestInterrupt(CPU *cpu, byte type);
void gbInterrupt(CPU *cpu, word address);

#endif
