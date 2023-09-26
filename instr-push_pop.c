
static void push(cpu_context * cc, uint32_t data)
{
    uint32_t sp;

    sp = read_16(cc, 0x18);
    sp -= 2;
    write_16(cc, sp, data);
    write_16(cc, 0x18, sp);
}

static uint32_t pop(cpu_context * cc)
{
    uint32_t sp;
    uint32_t data;

    sp = read_16(cc, 0x18);
    data = read_16(cc, sp);
    sp += 2;
    write_16(cc, 0x18, sp);
}

// Push waop word onto stack
//  opcode: 0xC8-0xCB
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_push(cpu_context * cc, uint32_t opcode)
{
    push(cc, read_16(cc, waop(cc, opcode)));
}

// Pop word off of stack and write to waop
//  opcode: 0xCC-0xCF
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_pop(cpu_context * cc, uint32_t opcode)
{
    write_16(cc, waop(cc, opcode), pop(cc));
}

// Push flags onto stack
//  opcode: 0xF2
//  flags: Z  N  C  V  VT ST I
//         0  0  0  0  0  0  0
//
static inline void instr_pushf(cpu_context * cc, uint32_t opcode)
{
    uint32_t data;

    data  = read_8(cc, 0x08);
    data += cc->status << 8;

    push(cc, data);

    cc->status = 0x00;
}

// Pop flags off of stack
//  opcode: 0xF3
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ?  ?  ?
//
static inline void instr_popf(cpu_context * cc, uint32_t opcode)
{
    uint32_t data;

    data = pop(cc);

    write_8(cc, 0x08, (uint8_t) data);
    cc->status = (uint8_t) (data >> 8);
}
