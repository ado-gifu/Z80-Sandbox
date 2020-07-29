#include "Z80.h" // Important - uncomment "#define LSB_FIRST" on x86 machines.
#include "main.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

char* Z80_RAM;
char* Z80_IO;
Z80* Z80_Ptr;

int main(int argc, char** argv)
{
    // Init.
    char FlagAllGood = -1;

    // Logic.
    Z80_Ptr = malloc(sizeof(Z80)); // New instance of Z80.
    Z80_RAM = malloc(MAX_RAM_SIZE);
    Z80_IO  = malloc(MAX_IO_SIZE);
    
    InitScreen();
    ClearArray(Z80_RAM, MAX_RAM_SIZE);
    ClearArray(Z80_IO,  MAX_IO_SIZE);

    // Furnish RAM with binary image.
    if(argc > 1)
    {
        // At least one argument present. Assume it's the raw memory.
        int NextInt = 0;

        FILE* InputImagePtr = fopen(argv[1], "r");

        //while(NextInt != EOF)
        for(int i = 0; NextInt != EOF; i++)
        {
            NextInt = fgetc(InputImagePtr);

            Z80_RAM[i] = (char) NextInt;
        } 
    }
    else
    {
        FlagAllGood = 0;
    }

    // Looks like everything went fine. Continue.
    if( FlagAllGood)
        ResetZ80(Z80_Ptr);
    
    while(FlagAllGood)
    {
        RunDevices();
    }

    // Return.
    return 0;
}

// Functions that handle curses calls.
void InitScreen()
{
    // Simply initializes the xcurses screen.
    initscr();
    refresh();
}


// Functions that handle Z80 and related stuff.
void ClearArray(char* Array, int Max)
{
    // Init, logic.
    for(int i = 0; i < Max; i++)
    {
        Array[i] = 0;
    }
}
