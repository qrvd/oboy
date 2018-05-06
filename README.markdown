## OBOY - The Gameboy emulator

Hello! This is a Gameboy emulator I've been making in my spare time
for a while, for educational purposes.

### How do I use it?

You may clone the respository and compile the emulator using `debug.bat`.
A GameBoy BIOS file is required, which you will have to obtain through legal means
and save it as `bios.bin` in the same folder as `build.bat`. Finally, you can
launch the emulator using `oboy romfile.gb`, where `romfile` is the path to the
Gameboy ROM you wish to emulate.

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

### Thanks to...

* @Immendes for the JSON file [listing all GameBoy instructions](https://github.com/lmmendes/game-boy-opcodes) along with their
individual timings and sizes. That saved me a lot of time.
* The developer of Realboy for [the overview](https://realboyemulator.wordpress.com/2013/01/01/the-nintendo-game-boy-1/) on the Gameboy BIOS
* PASTRAISER for their [handy table on GameBoy instructions](http://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html)
* Monegenel's [memory map](http://gameboy.mongenel.com/dmg/asmmemmap.html)
* Marc Rawer for hosting the [GameBoy CPU manual](http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf)
* bircd.org for the [additional GameBoy documentation](http://bgb.bircd.org/pandocs.htm)

### Licensing

See `LICENSE` and `docs/`. In addition, `tcc` is distributed under LGPL.
