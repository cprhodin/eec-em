
// Clear word register
//  opcode: 0x01
//  flags: Z  N  C  V  VT ST I
//         1  0  0  0  -  -  -
//
static inline void instr_clr(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, 0x0000);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, fZERO);
}

// Clear byte register
//  opcode: 0x11
//  flags: Z  N  C  V  VT ST I
//         1  0  0  0  -  -  -
//
static inline void instr_clrb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);

    write_8(cc, breg, 0x00);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, fZERO);
}

// Logical NOT word
//  opcode: 0x02
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -  -
//
static inline void instr_not(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);
    int32_t  op1  = (int32_t) (int16_t) read_16(cc, wreg);

    op1 = ~op1;
    write_16(cc, wreg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical NOT byte
//  opcode: 0x12
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_notb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    int32_t  op1  = (int32_t) (int8_t) read_8(cc, breg);

    op1 = ~op1;
    write_8(cc, breg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical AND word
//  opcode: 0x40-0x43
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_and3(cpu_context * cc, uint32_t opcode)
{
    int32_t op3   = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    int32_t op2   = (int32_t) (int16_t) read_16(cc, fetch(cc));
    uint32_t wreg = fetch(cc);

    op2 = op2 & op3;
    write_16(cc, wreg, (uint32_t) op2);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op2) ? fZERO     : 0) |
                   ((0  > op2) ? fNEGATIVE : 0)   );
}

// Logical AND byte
//  opcode: 0x50-0x53
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_andb3(cpu_context * cc, uint32_t opcode)
{
    int32_t op3   = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    int32_t op2   = (int32_t) (int8_t) read_8(cc, fetch(cc));
    uint32_t breg = fetch(cc);

    op2 = op2 & op3;
    write_8(cc, breg, (uint32_t) op2);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op2) ? fZERO     : 0) |
                   ((0  > op2) ? fNEGATIVE : 0)   );
}

// Logical AND word
//  opcode: 0x60-0x63
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_and(cpu_context * cc, uint32_t opcode)
{
    int32_t  op2  = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    uint32_t wreg = fetch(cc);
    int32_t  op1  = (int32_t) (int16_t) read_16(cc, wreg);

    op1 = op1 & op2;
    write_16(cc, wreg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical AND byte
//  opcode: 0x70-0x73
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_andb(cpu_context * cc, uint32_t opcode)
{
    int32_t  op2  = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    uint32_t breg = fetch(cc);
    int32_t  op1  = (int32_t) (int8_t) read_8(cc, breg);

    op1 = op1 & op2;
    write_8(cc, breg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical OR word
//  opcode: 0x80-0x83
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_or(cpu_context * cc, uint32_t opcode)
{
    int32_t  op2  = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    uint32_t wreg = fetch(cc);
    int32_t  op1  = (int32_t) (int16_t) read_16(cc, wreg);

    op1 = op1 | op2;
    write_16(cc, wreg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical OR byte
//  opcode: 0x90-0x93
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_orb(cpu_context * cc, uint32_t opcode)
{
    int32_t  op2  = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    uint32_t breg = fetch(cc);
    int32_t  op1  = (int32_t) (int8_t) read_8(cc, breg);

    op1 = op1 | op2;
    write_8(cc, breg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical XOR word
//  opcode: 0x84-0x87
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_xor(cpu_context * cc, uint32_t opcode)
{
    int32_t  op2  = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    uint32_t wreg = fetch(cc);
    int32_t  op1  = (int32_t) (int16_t) read_16(cc, wreg);

    op1 = op1 ^ op2;
    write_16(cc, wreg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

// Logical XOR byte
//  opcode: 0x94-0x97
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static void instr_xorb(cpu_context * cc, uint32_t addr)
{
    int32_t  op2  = (int32_t) (int8_t) read_8(cc, addr);
    uint32_t breg = fetch(cc);
    int32_t  op1  = (int32_t) (int8_t) read_8(cc, breg);

    op1 = op1 ^ op2;
    write_8(cc, breg, (uint32_t) op1);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == op1) ? fZERO     : 0) |
                   ((0  > op1) ? fNEGATIVE : 0)   );
}

static inline void instr_xorb_direct(cpu_context * cc, uint32_t opcode)
{
    instr_xorb(cc, baop_direct(cc));
}

static inline void instr_xorb_immediate(cpu_context * cc, uint32_t opcode)
{
    instr_xorb(cc, baop_immediate(cc));
}

static inline void instr_xorb_indirect(cpu_context * cc, uint32_t opcode)
{
    instr_xorb(cc, baop_indirect(cc));
}

static inline void instr_xorb_indexed(cpu_context * cc, uint32_t opcode)
{
    instr_xorb(cc, baop_indexed(cc));
}
