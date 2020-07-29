// Various defines.
#define MAX_RAM_SIZE 0x10000
#define MAX_IO_SIZE  0x100

#define VRAM_ADD_LSB 0x0 // These define the start of VRAM.
#define VRAM_ADD_MSB 0x1

#define VRAM_CNUM_LSB 0x2 // These two define how many characters to display.
#define VRAM_CNUM_MSB 0x3


// Implement this method to prepare the screen.
void InitScreen();

// Run devices.
void RunDevices();
void RunVRAMDevice();

// Other.
void ClearArray(char* Array, int Max);
