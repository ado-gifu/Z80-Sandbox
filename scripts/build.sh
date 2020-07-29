#!/bin/bash

gcc -c -g           src_z80/Z80.c -o obj/Z80.o
gcc -c -g -Isrc_z80 src/devices.c -o obj/devices.o
gcc -c -g -Isrc_z80 src/main.c    -o obj/main.o

gcc obj/* -lncurses -o bin/main

z80asm src_asm/rom.z80 -o bin/rom.bin
