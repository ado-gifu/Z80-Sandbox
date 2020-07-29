#include "Z80.h" // Important - uncomment "#define LSB_FIRST" on x86 machines.
#include "main.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

extern char* Z80_RAM;
extern char* Z80_IO;
extern Z80* Z80_Ptr;

void RunDevices()
{
    // Run Z80 first in the cycle.
    RunZ80(Z80_Ptr);

    // Runs all devices.
    RunVRAMDevice();
}

//void RefreshScreen()
void RunVRAMDevice()
{
    // Init.
    word VRAM_Address  = 0x0;
    word VRAM_Char_Num = 0x0;

    // Logic.
    // Prepare the indices. Please keep in mind this was developed on x86.
    // Endianness may break this.
    // Both the address of VRAM as well as the number of characters to be
    // written is specified on four ports within Z80's IO space.
    VRAM_Address = Z80_IO[ VRAM_ADD_MSB ];
    VRAM_Address = (VRAM_Address << 8) | Z80_IO[ VRAM_ADD_LSB ];

    VRAM_Char_Num = Z80_IO[ VRAM_CNUM_MSB ];
    VRAM_Char_Num = (VRAM_Char_Num << 8) | Z80_IO[ VRAM_CNUM_LSB ];

    // Wrapper for xcurses refresh function.
    mvaddnstr(0, 0, &Z80_RAM[ VRAM_Address ], VRAM_Char_Num);
    refresh();
}

void WrZ80(register word Addr, register byte Value)
{
    // Writes to Z80's memory.
    // Init, logic.
    Z80_RAM[Addr] = Value;
}

byte RdZ80(register word Addr)
{
    // Reads from Z80's memory.
    // Init, logic, return.    
    return Z80_RAM[Addr];
}

void OutZ80(register word Port,register byte Value)
{
    // Writes to one of Z80's ports.
    // Only consider the lower byte from Port, then store Value.
    // Init, logic.    
    Port &= 0xFF; // Extract a single byte.
    
    Z80_IO[Port] = Value;
}

byte InZ80(register word Port)
{
    // Reads from one of Z80's ports.
    // Init, logic, return.    
    Port &= 0xFF;

    return Z80_IO[Port];
}

void PatchZ80(register Z80 *R)
{
    // Leave for now.
}

word LoopZ80(register Z80 *R)
{
    // Leave for now.
    return INT_QUIT;
}

/*void JumpZ80(word PC)
{
    // Just in case I need to implement this.
}*/
