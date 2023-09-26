#include <stdio.h>
#include <stdint.h>

#include "eec-em.h"
#include "instr-tab.h"

int invalid_instruction(target_state * cpu, uint8_t opcode)
{
}

int instr_mul(target_state * cpu, uint8_t opcode)
{
}

int instr_mulb(target_state * cpu, uint8_t opcode)
{
}

int instr_div(target_state * cpu, uint8_t opcode)
{
}

int instr_divb(target_state * cpu, uint8_t opcode)
{
}

uint8_t fetch_byte(unsigned int pc)
{
    return (uint8_t) pc;
}

int prefixed_instruction_fetch(target_state * cpu, uint8_t opcode)
{
    opcode = get_bitfield(cpu->pc, 8, 8);

    i8061_prefixed_instruction_set[opcode](cpu, opcode);
}

int instruction_fetch(target_state * cpu)
{
    uint8_t opcode;

    opcode = get_bitfield(cpu->pc, 0, 8);

    i8061_instruction_set[opcode](cpu, opcode);
}
