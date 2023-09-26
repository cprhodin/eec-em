
// Shift byte register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shrb(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_8(cc, reg);
    data = data >> count;
    write_8(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Shift word register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shr(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_16(cc, reg);
    data = data >> count;
    write_16(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Shift long register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shrl(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_32(cc, reg);
    data = data >> count;
    write_32(cc, reg, data);


    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Shift byte register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shrab(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    int32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = (int32_t) (int8_t) read_8(cc, reg);
    data = data >> count;
    write_8(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Arithmetic shift word register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shra(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    int32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = (int32_t) (int16_t) read_16(cc, reg);
    data = data >> count;
    write_16(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Shift long register right
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  0  -  0  -
//
static inline void instr_shral(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    int32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = (int32_t) read_32(cc, reg);
    data = data >> count;
    write_32(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW | fSTICKY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fSTICKY       : 0)   );
}

// Shift byte register left
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_shlb(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_8(cc, reg);
    data = data << count;
    write_8(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fOVERFLOW     : 0) |
               ((0 >  data) ? fOVERFLOWTRAP : 0)   );
}

// Shift word register left
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_shl(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_16(cc, reg);
    data = data << count;
    write_16(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fOVERFLOW     : 0) |
               ((0 >  data) ? fOVERFLOWTRAP : 0)   );
}

// Shift long register left
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_shll(cpu_context * cc, uint32_t opcode)
{
    uint32_t count = fetch(cc);
    uint32_t reg = fetch(cc);
    uint32_t data;

    if (16 <= count) count = read_8(cc, count);
    count = count & 0xF;

    data = read_32(cc, reg);
    data = data << count;
    write_32(cc, reg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0) |
               ((0 >  data) ? fCARRY        : 0) |
               ((0 >  data) ? fOVERFLOW     : 0) |
               ((0 >  data) ? fOVERFLOWTRAP : 0)   );
}
