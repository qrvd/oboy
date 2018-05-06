#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "memory.h"
#include "gpu.h"
#include "gb.h"

void step(struct CPU *cpu, bool doDebugStep) {
	long duration = (doDebugStep ? gbDebugStep(cpu) : gbStep(cpu));
	memoryStep(duration, cpu);

	#ifndef SHELL_ONLY
	gpuStep(duration);
	#endif

	if (cpu->PC > 0x100 && ((readByte(0xFF50) & 0x01) != 0)) exit(1);
}

int main(int argc, char **argv) {

	// When linking with SDL 1.2, you always have to explicitly open
	// the standard output.
	freopen( "CON", "w", stdout );
	freopen( "CON", "w", stderr );


	// Count arguments.
	if (argc < 2) {
		puts("pass me a rom path");
		return 1;
	}

	// Initialize.
	memoryInit(argv[1]);
	writeByte(0xFFFF, 0xFF);
	struct CPU cpu = {0};

	#ifdef SHELL_ONLY
	enum {
		WAITADDR,
		WAITOP,
		RUNNING,
		COUNTDOWN,
		INACTIVE,
		ACTIVE
	} status;
	status = ACTIVE;
	word awaiting = 0;
	char input[256];
	bool quiet = false;
	#else
	gpuInit(&cpu);
	#endif

	// Go!
	bool running = true;

	while (running) {

#ifdef 	SHELL_ONLY

		byte oldPC = cpu.PC;

	  switch (status) {

	  	case ACTIVE: {
	  		printf("%04x >> ", cpu.PC);
	  		fgets(input, 256, stdin);

  			#define command(name) (strncmp(input, (name), strlen((name))) == 0)

  			if (command("status") || command("S")) {
  				printf("Status:\n  sp: %04x bc: %04x de: %04x\n  hl: %04x af: %04x f:: %c%c%c%c\n  op: %02x clock: %ld\n",
  				    cpu.SP, cpu.BC, cpu.DE, cpu.HL, cpu.AF,
  				    cpu.F.Z ? 'Z' : 'z', cpu.F.S ? 'S' : 's', cpu.F.H ? 'H' : 'h', cpu.F.C ? 'C' : 'c', readByte(cpu.PC), cpu.clock);
  			} else if (command("go") || command("goaddr")) { //< stop before the given address
  				status = WAITADDR;
  				awaiting = readHexNumber(input + /* strlen("go") */  2);
  			} else if command("goop") { //< stop before the given opcode
  				status = WAITOP;
  				awaiting = readHexNumber(input + /* strlen("goop") */ 4);
  			} else if command("run") { //< keep running.
  				status = RUNNING;
  			} else if command("step") {
  				gbDebugStep(&cpu);
  		  } else if command("quit") {
  		  	exit(1);
  		  } else if command("rb") { //< read a byte
  				word addr = readHexNumber(input + /* strlen("rb") */ 2);
  				printf("%04x: %02x\n", addr, readByte(addr));
  			} else if command("rw") { //< read a word
  				word addr = readHexNumber(input + /* strlen("rw") */ 2);
  				printf("%04x: %04x\n", addr, readWord(addr));
  			} else if command("wb") { //< write a byte
  				word addr = readHexNumber(input + /* strlen("wb") */ 2);
  				printf("make sure to include '0x'\nwrite what to %04x?> ", addr);
  				fgets(input, 256, stdin);
  				byte to_write = readNumber(input);
  				writeByte(addr, to_write);
  				printf("%04x: %02x\n", addr, readByte(addr));
  			} else if command("ww") { //< write a word
  				word addr = readHexNumber(input + /* strlen("ww") */ 2);
  				printf("make sure to include '0x'\nwrite what to %04x?> ", addr);
  				fgets(input, 256, stdin);
  				word to_write = readNumber(input);
  				writeWord(addr, to_write);

  				printf("%04x: %04x\n", addr, readWord(addr));
  			} else if command("do") { //< perform a regular op (note that arguments have to be dealt with beforehand!)
  				word op = readHexNumber(input + /* strlen("do") */ 2);

  				// We want to use gbDebugStep without issues, so write over the PC for a moment.
  				word pc = cpu.PC;
  				word oldOp = readByte(pc);

  				writeByte(pc, op);
  					gbDebugStep(&cpu);
  				writeByte(pc, oldOp);
  			} else if (command("shh") || command("quiet") || command("Q")) { //< print while automatic or not?
  				quiet = !quiet;
  				printf("Quiet: %c\n", quiet ? 'Y' : 'N');
  			} else if command("tick") { //< hold for some cycles
  				long time = readNumber(input + /* strlen("tick") */ 4);
  				cpu.clock += time;
  				memoryStep(time, &cpu);

  				#ifndef SHELL_ONLY
						gpuStep(duration);
					#endif

  			} else if command("sb") { //< skip to 0x100 without fuss.
  				// Only if the BIOS is enabled though.
  				if (readByte(0xFF50) != 0x01) {
  					puts("Skipping BIOS quietly...");
  					quiet = true;
  					status = WAITADDR;
  					awaiting = 0x0100;
  				}
  			} else if command("count") { // < do this many instructions before returning to activity
  				awaiting = readNumber(input + /* strlen count */ 5);
  				status = COUNTDOWN;
  			} else if command("reset") {
  				struct CPU newCpu = {0};
  				cpu = newCpu;
  				writeByte(0xFFFF, 0xFF);
  			} else if command("exit") {
  				return 0;
  			} else {
  				printf("available commands:\n  status(S) goaddr(go) goop quiet(Q,shh) nomore reset\n  rb rw wb ww tick sb do run\n");
  			}

  			continue; //< hacky bugfix to run a cycle before checking interrupts and lockups.

	  		break;
  		  #undef command
	  	}
	  	case RUNNING:
	  		step(&cpu, !quiet);
	  		break;
	  	case WAITADDR:
	  		if (cpu.PC == awaiting)
	  			status = ACTIVE;
	  		else
	  			step(&cpu, !quiet);
	  		break;
	  	case WAITOP:
	  		if (readByte(cpu.PC) == awaiting)
	  			status = ACTIVE;
	  		else
	  			step(&cpu, !quiet);
	  		break;
	  	case COUNTDOWN:
	  		if (awaiting-- == 0)
	  			status = ACTIVE;
	  		else
	  			step(&cpu, !quiet);
	  		break;
	  	case INACTIVE:
	  		break;
	  }

	  if (oldPC == cpu.PC && status != ACTIVE) {
	  	// We locked up. Now let's retake control.
			status = ACTIVE;
			quiet = false;
			puts("We're stuck (PC didn't change!)\nQuiet: N");
	  	continue;
	  }

#else
	  step(&cpu, false);

#endif

	  // Check if any enabled interrupts (IE) are being requested (IF).
	  if (cpu.interrupts) {
	  	byte IE = readByte(0xFFFF);
	  	byte IF = readByte(0xFF0F);
	  	byte masked = IE & IF;

	  	if (masked) {

	  		#define DEF_INTERRUPT(type) \
	  			if (masked & (type##_INTERRUPT_MASK)) { \
	  				IF &= (0xff - type##_INTERRUPT_MASK); \
	  				gbInterrupt(&cpu, (type##_ISR)); \
	  			} \

	  		DEF_INTERRUPT(VBLANK);
	  		DEF_INTERRUPT(LCD);
	  		DEF_INTERRUPT(TIMER);
	  		DEF_INTERRUPT(SERIAL);
	  		DEF_INTERRUPT(JOYPAD);

	  		writeByte(0xFF0F, IF);
	  		writeByte(0xFFFF, IE);

	  		#undef DEF_INTERRUPT
	  	}
	  }
	}

	return 0;
}
