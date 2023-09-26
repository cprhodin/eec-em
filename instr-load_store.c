
// Load word
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ld(cpu_context * cc, uint32_t opcode)
{
    uint32_t op1  = read_16(cc, waop(cc, opcode));
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, op1);
}

// Load byte
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ldb(cpu_context * cc, uint32_t opcode)
{
    uint32_t op1  = read_8(cc, baop(cc, opcode));
    uint32_t breg = fetch(cc);

    write_8(cc, breg, op1);
}

// Load byte sign-extend to word
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ldbse(cpu_context * cc, uint32_t opcode)
{
    int32_t op1   = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, (uint32_t) op1);
}

// Load byte zero-extend to word
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ldbze(cpu_context * cc, uint32_t opcode)
{
    uint32_t op1  = read_8(cc, baop(cc, opcode));
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, op1);
}

// Store word
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_st(cpu_context * cc, uint32_t opcode)
{
    uint32_t addr = waop(cc, opcode);
    uint32_t wreg = fetch(cc);

    write_16(cc, addr, read_16(cc, wreg));
}

// Store byte
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_stb(cpu_context * cc, uint32_t opcode)
{
    uint32_t addr = baop(cc, opcode);
    uint32_t breg = fetch(cc);

    write_8(cc, addr, read_8(cc, breg));
}
