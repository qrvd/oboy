## OBOY - The Gameboy emulator

Hello! This is a Gameboy emulator I've been making in my spare time
for a while, for educational purposes.

You may clone the respository and compile the emulator using `debug.bat`.
Note that this presumes MinGW's `gcc` and `g++` is installed and in your PATH.
If you have `tcc`, the Tiny C compiler installed under the `tcc` directory,
you may use `tcc.bat` to quickly run the code, provided `tcc` is in your PATH.

### Roadmap

This is still a work in progress, but some significant progress has already
been made.

Implemented:
* Control unit (`gb.c` and `gb.h`)
* Command-line debugger (`oboy.c`)
* Memory layout (`memory.c` and `memory.h`)
* All "non-obscure" instructions (`opcodes.h`, `obcode_generate.rb`, `opcode_table.h`)

Working on:
* Audio emulation
* GPU emulation (`gpu.c` and `gpu.h`)
* User interface
* The rest of the CPU instructions
