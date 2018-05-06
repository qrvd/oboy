#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

// Dear old interrupt addresses.
#define VBLANK_ISR (0x0040)
#define LCD_ISR (0x0048)
#define TIMER_ISR (0x0050)
#define SERIAL_ISR (0x0058)
#define JOYPAD_ISR (0x0060)

// Initialize. Use this before running.
void memoryInit(const char *romPath);

// Update timers.
struct CPU;
void memoryStep(long cycles, struct CPU *cpu);

// Write or read a word or a byte.
void writeByte(word address, byte b);
void writeWord(word address, word w);
byte readByte(word address);
word readWord(word address);

#endif