#ifndef GPU_H
#define GPU_H

#include "common.h"

struct SDL_Surface;
void gpuInit(struct CPU *cpu);
void gpuUpdateVRAM(word address, byte value);
void gpuStep(long duration);

#endif
