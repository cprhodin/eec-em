#include <stdio.h>

#include "i8061.h"

#define INSTRUCTION_DEF(opcode, mnemonic, bitfields, flags) [opcode] = mnemonic

char * instr[256] =
{
    I8061_INSTRUCTION_SET
};

void main(void)
{
	int i;
	
	for (i = 0; i < 256; i++)
	{
		/*
		if (instr[i] != NULL)
		    printf("    [0x%02x]          = instr_%s,\n", i, instr[i]);
		else
		    printf("    [0x%02x]          = invalid_instruction,\n", i);
		*/
		if (instr[i] != NULL)
		    printf("int instr_%s(void);\n", instr[i]);
		else
		    printf("int invalid_instruction(void);\n");
	}
}
