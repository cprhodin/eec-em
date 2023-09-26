
// Two's complement word register
//  opcode: 0x03
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_neg(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);
    int32_t data;

    data = (int32_t) (int16_t) read_16(cc, wreg);
    data = 0 - data;
    write_16(cc, wreg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO                        : 0) |
                   ((0x8000  & data) ? fNEGATIVE                    : 0) |
                   ((0       > data) ? fCARRY                       : 0) |
                   ((0       > data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}

// Two's complement byte register
//  opcode: 0x13
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_negb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    int32_t data;

    data = (int32_t) (int8_t) read_8(cc, breg);
    data = 0 - data;
    write_8(cc, breg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO                        : 0) |
                   ((0x8000  & data) ? fNEGATIVE                    : 0) |
                   ((0       > data) ? fCARRY                       : 0) |
                   ((0       > data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}

// Decrement word register
//  opcode: 0x04
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_dec(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);
    uint32_t data;

    data = read_16(cc, wreg);
    data = data - 1;
    write_16(cc, wreg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO                        : 0) |
                   ((0x8000  & data) ? fNEGATIVE                    : 0) |
                   ((0       > data) ? fCARRY                       : 0) |
                   ((0       > data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}

// Decrement byte register
//  opcode: 0x14
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_decb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    uint32_t data;

    data = read_8(cc, breg);
    data = data - 1;
    write_8(cc, breg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO                        : 0) |
                   ((0x8000  & data) ? fNEGATIVE                    : 0) |
                   ((0       > data) ? fCARRY                       : 0) |
                   ((0       > data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}

// Sign extend word register to long
//  opcode: 0x05
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_ext(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);
    int32_t data;

    data = (int32_t) (int16_t) read_16(cc, wreg);
    write_32(cc, wreg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == data) ? fZERO     : 0) |
                   ((0 >  data) ? fNEGATIVE : 0)   );
}

// Sign extend byte register to word
//  opcode: 0x15
//  flags: Z  N  C  V  VT ST I
//         ?  ?  0  0  -  -  -
//
static inline void instr_extb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    int32_t data;

    data = (int32_t) (int8_t) read_8(cc, breg);
    write_16(cc, breg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0 == data) ? fZERO     : 0) |
                   ((0 >  data) ? fNEGATIVE : 0)   );
}

// Increment word register
//  opcode: 0x06
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_inc(cpu_context * cc, uint32_t opcode)
{
    uint32_t wreg = fetch(cc);
    int32_t data;

    data = (int32_t) (int16_t) read_16(cc, wreg);
    data = data + 1;
    write_16(cc, wreg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO | fCARRY               : 0) |
                   ((0       > data) ? fNEGATIVE                    : 0) |
                   ((32768  == data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}

// Increment byte register
//  opcode: 0x16
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_incb(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    int32_t data;

    data = (int32_t) (int8_t) read_8(cc, breg);
    data = data + 1;
    write_8(cc, breg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY | fOVERFLOW);
    SET_STATUS(cc, ((0      == data) ? fZERO | fCARRY               : 0) |
                   ((0       > data) ? fNEGATIVE                    : 0) |
                   ((128    == data) ? (fOVERFLOW | fOVERFLOWTRAP ) : 0)   );
}
