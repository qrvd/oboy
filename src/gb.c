#include "gb.h"
#include "common.h"
#include "memory.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void gbPush(struct CPU *cpu, byte b) {
  writeByte(cpu->SP, b);
  cpu->SP--;
}

void gbPush16(struct CPU *cpu, word w) {
  gbPush(cpu, w >> 8);
  gbPush(cpu, w & 0xFF);
}

byte gbPop(struct CPU *cpu) {
  cpu->SP++;
  return readByte(cpu->SP);
}

word gbPop16(struct CPU *cpu) {
  byte low = gbPop(cpu);
  byte high = gbPop(cpu);
  return makeWord(high, low);
}

void gbCall(struct CPU *cpu, word address) {
  gbPush16(cpu, cpu->PC);
  cpu->PC = address;
}

// This header file implements all the LR35902 opcodes.
#include "opcodes.h"

// This table defines all the regular LR35902 opcodes,
// plus the Z80's extended opcodes (which start at index 256).
struct Instruction gbInstructions[256 + 256] = {
  #include "opcode_table.h"
};

long gbDispatch(struct CPU *cpu, byte op) {

	// Choose the correct instruction.
	struct Instruction inst = gbInstructions[op];
	if (op == 0xCB) {
		cpu->clock += 4;
		byte exOp = readByte(cpu->PC + 1);
		inst = gbInstructions[256 + exOp];
	}

	// Decode it.
	word operands = (op == 0xCB ? cpu->PC + 2 : cpu->PC + 1);
	word a16 = readWord(operands);
	byte d8 = readByte(operands);
	ibyte r8 = (ibyte)d8;
	long oldClock = cpu->clock;

	// Execute and calculate the 'real' duration, which may differ
	// from the default one in certain jump instructions for example.
	inst.execute(cpu, d8, r8, a16);
	long duration = inst.duration + (cpu->clock - oldClock);

	// Update internal state.
	cpu->PC += inst.length;
	cpu->clock += inst.duration;

	return duration;
}

long gbStep(struct CPU *cpu) {
	byte op = readByte(cpu->PC);
	long duration = gbDispatch(cpu, op);
	return duration;
}

void gbInterrupt(struct CPU *cpu, word address) {
	cpu->interrupts = false;

	// What about CB?
	gbPush16(cpu, cpu->PC + 1);

	cpu->PC = address;
}

void gbRequestInterrupt(CPU *cpu, byte type) {
	byte IF = readByte(0xFF0F);
	IF |= type;
	writeByte(0xFF0F, IF);
}

long gbDebugStep(struct CPU *cpu) {
	struct CPU old = *cpu;

	byte op = readByte(cpu->PC);
	int cb = 0;
	if (op == 0xCB) { // CB prefix
		op = readByte(cpu->PC + 1);
		cb = 1;
	}
	printf("[%04x] %s\n", cpu->PC, gbInstructions[(cb ? 256 : 0) + op].mnemonic);

	long duration = gbStep(cpu);

  #define compare_print(field) if (old. field != cpu-> field) { printf("%s: %04x -> %04x\n", #field, old.field, cpu->field); }
		compare_print(SP);
		compare_print(interrupts);
		compare_print(halted);
  	compare_print(AF);
  	compare_print(BC);
  	compare_print(DE);
  	compare_print(HL);

  	// Some sugar
  	#define print_flag(lower, upper, expr) ((expr) ? (upper) : (lower))
  	if ((old.AF & 0xFF00) != (cpu->AF & 0xFF00)) {
  		printf("f: %c%c%c%c -> %c%c%c%c\n",
  			print_flag('Z', 'z', cpu->F.Z), print_flag('S', 's', cpu->F.S), print_flag('H', 'h', cpu->F.H), print_flag('C', 'c', cpu->F.C),
  			print_flag('Z', 'z', cpu->F.Z), print_flag('S', 's', cpu->F.S), print_flag('H', 'h', cpu->F.H), print_flag('C', 'c', cpu->F.C));
  	}
  #undef compare_print

  return duration;
}