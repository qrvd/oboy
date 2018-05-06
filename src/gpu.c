#include "gpu.h"
#include "gb.h"
#include "memory.h"
#include "SDL/SDL.h"
#include <stdlib.h>
#include <stdio.h>

extern void gbRequestInterrupt(CPU *cpu, byte type);

#define SCREEN_W (160)
#define SCREEN_H (144)
#define BYTES_PER_PIXEL (3) /* RGB */

long gpuModeClock = 0;
int gpuMode = 0;
int gpuCurrentLine = 0;
byte tileset[384][8][8] = {0};

byte framebuffer[SCREEN_W * SCREEN_H * BYTES_PER_PIXEL];
byte palette[4][BYTES_PER_PIXEL] = {
	{255, 255, 255}, {192, 192, 192},
	{96, 96, 96}, {0, 0, 0}
};

struct BGPalette {
	union {
		union {
			byte _3: 2;
			byte _2: 2;
			byte _1: 2;
			byte _0: 2;
		};

		byte data;
	};
};

SDL_Surface *gpuScreen = NULL;
struct CPU *gbCPU;

void gpuInit(struct CPU *cpu) {
	gbCPU = cpu;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetCaption("GAMEBOY", NULL);
	gpuScreen = SDL_SetVideoMode(640, 480, 0, SDL_SWSURFACE|SDL_DOUBLEBUF);
	if (gpuScreen == NULL) {
		printf("Oops: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_PixelFormat *format = gpuScreen->format;
	printf("Format:\nR %x\nG %x\nB %x\nA %x\n", format->Rmask, format->Gmask, format->Bmask, format->Amask);

	Uint32 c = 0x0000FF00;
	SDL_FillRect(gpuScreen, &gpuScreen->clip_rect, c);
}

void gpuUpdateVRAM(word address, byte value) {

	// Get the base address for the row.
	address &= 0x1FFE;

	// Find the tile and row that was updated
	int tile = (address >> 4) & 0x1FF;
	int y = (address >> 1) & 0x7;

	for (int x = 0; x < 8; x++) {

		// Find the bit index for the pixel
		int sx = 1 << (7 - x);

		// Update the tileset
		tileset[tile][y][x] =
			((readByte(0x8000 + address) & sx) ? 1 : 0) +
			((readByte(0x8000 + address + 1) & sx) ? 2 : 0);
	}
}

struct LCDC {
	union {
		union {
			bool display:1;
			byte windowTileMap:1;
			bool window:1;
			byte bgTileSet:1;
			byte bgTileMap:1;
			byte spriteSize:1;
			bool sprites:1;
			bool background:1;
		};

		byte _data;
	};
};

void gpuRenderLine() {
	// Each tile is 16 bytes (8 x 8 x 2bpp)
	// So each pixel has 2 bits to choose a specific color for it.
	// That means the pixel array will consist of the actual RGB values.
	// gpuSetPixel(x, y, colors[px]);

	int scrollY = readByte(0xFF42);
	int scrollX = readByte(0xFF43);
	struct LCDC lcdc = {0};
	lcdc._data = readByte(0xFF40);

	// VRAM offset for the tile MAP.
	int mapOffset = lcdc.bgTileMap ? 0x1C00 : 0x1800;

	// Which tile line shall be used?
	mapOffset += ((gpuCurrentLine + scrollY) & 0xFF) >> 3;

	// Which tile line shall be used?
	int lineOffset = scrollX >> 3;

	// Now what line of pixels is that?
	int y = (gpuCurrentLine + scrollY) & 0x7;

	// Tile line offset
	int x = scrollX & 0x7;

	// Where shall this be rendered?
	int drawOffset = gpuCurrentLine * SCREEN_W * BYTES_PER_PIXEL;

	// Get the index
	byte *color;
	int tile = readByte(0x8000 + mapOffset + lineOffset);

	// Convert signed tile indices to unsigned, for our convenience
	if (lcdc.bgTileSet && tile < 128) { tile += 256; }

	// Draw
	for (int i = 0; i < SCREEN_W; i++) {
		// Map the tile pixel using the palette
		color = palette[tileset[tile][y][x]];

		// Draw this.
		if (color[0] != 0xff) printf("Pixel (%d, %d) is (%02x, %02x, %02x)\n",
										i, gpuCurrentLine + scrollY, color[0], color[1], color[2]);
		for (int b = 0; b < BYTES_PER_PIXEL; b++) {
			framebuffer[drawOffset+b] = color[b];
		}
		drawOffset += BYTES_PER_PIXEL;

		// Begin with next line when done with this one
		x++;
		if (x == 8) {
			x = 0;
			lineOffset = (lineOffset + 1) & 31;
			tile = readByte((word)0x8000 + mapOffset + lineOffset);
			if (lcdc.bgTileSet && tile < 128) { tile += 256; }
		}
	}
}

void gpuDisplay() {

	SDL_Surface *frame = SDL_CreateRGBSurfaceFrom(
			(void*)framebuffer,
			SCREEN_W,
			SCREEN_H,
			BYTES_PER_PIXEL * 8,
			SCREEN_W * BYTES_PER_PIXEL,
			0xFF0000,
			0x00FF00,
			0x0000FF,
			0);

	if (frame == NULL) {
		printf("Pixel array fail: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_BlitSurface(frame, NULL, gpuScreen, NULL);
	SDL_Flip(gpuScreen);
	SDL_Delay(500);
	SDL_FreeSurface(frame);
}

bool every(long numCycles) {

	if (gpuModeClock >= numCycles) {
		while (gpuModeClock - numCycles >= 0) gpuModeClock -= numCycles;
		gpuModeClock = 0;
		return true;
	}
	return false;
}

void gpuStep(long duration) {

	// Silly events.
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
						exit(1);
	}

	gpuModeClock += duration;
	writeByte(0xFF47, (byte)gpuCurrentLine);

	switch (gpuMode) {

		case 0:
			if (every(4560)) {
				gpuCurrentLine = 0;
				gpuMode = 2;
			}
			break;

		// After the final horizontal blank, flip the screen surface
		case 1: {
			if (every(204)) {

				gpuCurrentLine++;

				// Index 144 is the 145th line, so we're done.
				if (gpuCurrentLine == 144) {

					// Enter VBlank, but make sure to
					// display first, since the Vblank code is too brittle to do that.
					gpuDisplay();
					gpuMode = 0;

					// Fire a start-of-VBlank interrupt.
					gbRequestInterrupt(gbCPU, VBLANK_INTERRUPT_MASK);

				} else {

					// Access OAM again, for drawing next line.
					gpuMode = 2;
				}
			}
			break;
		}

		// Access OAM for 80 cycles
		case 2:
			if (every(80)) gpuMode = 3;
			break;

		// Access VRAM once a scanline.
		case 3: {
			if (every(172)) {

				// Draw a scanline.
				gpuRenderLine();

				// HBlank
				gpuMode = 1;
			}

			break;
		}

		default: {
			printf("Undefined GPU mode %d\n", gpuMode);
			exit(1);
		}
	}
}
