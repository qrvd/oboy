@echo off
:: Regenerate the opcodes.
:: Assumes `pwd` is the root of the project.
cd src
ruby opcode_generate.rb && echo Generated the opcodes.
cd ..

:: Compiling it this way to avoid various linker errors.
g++ -D SHELL_ONLY -Wall -DDEBUG -Iinclude -fexceptions -g -c src/oboy.c -o oboy.o
g++ -Wall -DDEBUG -Iinclude -fexceptions -g -c src/gb.c -o gb.o
g++ -Wall -DDEBUG -Iinclude -fexceptions -g -c src/memory.c -o memory.o
g++ -Wall -DDEBUG -Iinclude -fexceptions -g -c src/gpu.c -o gpu.o
g++ -Wall -DDEBUG -Iinclude -fexceptions -g -c src/common.c -o common.o
g++ -Llib -o oboy gb.o memory.o gpu.o common.o oboy.o -lmingw32 -lSDLmain -lSDL
del /q *.o