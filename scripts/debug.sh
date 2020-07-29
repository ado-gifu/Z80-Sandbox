#!/bin/bash
gdb bin/main -ex "tui enable" -d src -d src_Z80 -ex "b main.c:14" -ex "start bin/rom.bin"
