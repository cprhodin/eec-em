#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "i8061.h"
#include "instr-tab.h"

extern void reset(cpu_context * cc);
extern void execute(cpu_context * cc);

cpu_context cc;

// i8061 Memory Space
static uint8_t target_memory[65536];

int main(void)
{
    FILE * romfile;
    size_t num_bytes;
    int i;

    printf("\nEEC-IV Instruction Emulator\n\n");

    cc.target_memory = target_memory;

    reset(&cc);

    romfile = fopen("la3.bin", "r");
    if (!romfile)
    {
        printf("\n\nFATAL ERROR: could not open ROM file\n");
        exit(1);
    }

    num_bytes = fread(&target_memory[8192], sizeof(uint8_t), 65536 - 8192, romfile);
    printf("Read %d bytes from ROM file: %s\n", num_bytes, "la3.bin");

    printf("0x%08X:", cc.pc - cc.target_memory);

    for (i = 0; i < 100; i++)
    {
        execute(&cc);
        printf("\n0x%08X:", cc.pc - cc.target_memory);
    }

    return 0;
}
