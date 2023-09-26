#ifndef _INSTR_TAB_H
#define _INSTR_TAB_H

typedef struct _cpu_context
{
    // Base Address of Target Memory
    uint8_t * target_memory;

    // Program Counter
    uint8_t * pc;

    // Stack Pointer
//    uint8_t * sp;

    // Status Bits
    uint8_t status;
} cpu_context;

#endif // _INSTR_TAB_H
