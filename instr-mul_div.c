
// Multiply two unsigned 16-bit numbers for a 32-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulu3(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3  = read_16(cc, waop(cc, opcode));
    uint32_t op2  = read_16(cc, fetch(cc));
    uint32_t lreg = fetch(cc);

    write_32(cc, lreg, op2 * op3);
}

// Multiply two unsigned 8-bit numbers for a 16-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulub3(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3  = read_8(cc, baop(cc, opcode));
    uint32_t op2  = read_8(cc, fetch(cc));
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, op2 * op3);
}

// Multiply two unsigned 16-bit numbers for a 32-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulu(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop(cc, opcode));
    uint32_t lreg = fetch(cc);
    uint32_t op1  = read_16(cc, lreg);

    write_32(cc, lreg, op1 * op2);
}

// Multiply two unsigned 8-bit numbers for a 16-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulub(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop(cc, opcode));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_8(cc, wreg);

    write_16(cc, wreg, op1 * op2);
}

// Multiply two signed 16-bit numbers for a 32-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mul3(cpu_context * cc, uint32_t opcode)
{
    int32_t op3   = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    int32_t op2   = (int32_t) (int16_t) read_16(cc, fetch(cc));
    uint32_t lreg = fetch(cc);

    write_32(cc, lreg, op2 * op3);
}

// Multiply two signed 8-bit numbers for a 16-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulb3(cpu_context * cc, uint32_t opcode)
{
    int32_t op3   = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    int32_t op2   = (int32_t) (int8_t) read_8(cc, fetch(cc));
    uint32_t wreg = fetch(cc);

    write_16(cc, wreg, op2 * op3);
}

// Multiply two signed 16-bit numbers for a 32-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mul(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int16_t) read_16(cc, waop(cc, opcode));
    uint32_t lreg = fetch(cc);
    int32_t op1   = (int32_t) (int16_t) read_16(cc, lreg);

    write_32(cc, lreg, op1 * op2);
}

// Multiply two signed 8-bit numbers for a 16-bit result
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  U  -
//
static inline void instr_mulb(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int8_t) read_8(cc, baop(cc, opcode));
    uint32_t wreg = fetch(cc);
    int32_t op1   = (int32_t) (int8_t) read_8(cc, wreg);

    write_16(cc, wreg, op1 * op2);
}

// Divide a 32-bit unsigned number by a 16-bit number
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_divu_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t lreg = fetch(cc);
    uint32_t op1  = read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_divu_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t lreg = fetch(cc);
    uint32_t op1  = read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_divu_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t lreg = fetch(cc);
    uint32_t op1  = read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_divu_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t lreg = fetch(cc);
    uint32_t op1  = read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

// Divide a 16-bit unsigned number by a 8-bit number
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_divub_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divub_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divub_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divub_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

// Divide a 32-bit signed number by a 16-bit number
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_div_direct(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int16_t) read_16(cc, waop_direct(cc));
    uint32_t lreg = fetch(cc);
    int32_t op1   = (int32_t) read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_div_immediate(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int16_t) read_16(cc, waop_immediate(cc));
    uint32_t lreg = fetch(cc);
    int32_t op1   = (int32_t) read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_div_indirect(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int16_t) read_16(cc, waop_indirect(cc));
    uint32_t lreg = fetch(cc);
    int32_t op1   = (int32_t) read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

static inline void instr_div_indexed(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int16_t) read_16(cc, waop_indexed(cc));
    uint32_t lreg = fetch(cc);
    int32_t op1   = (int32_t) read_32(cc, lreg);

    write_16(cc, lreg, op1 / op2);
    write_16(cc, lreg + 2, op1 % op2);
}

// Divide a 16-bit signed number by a 8-bit number
//  opcode:
//  flags: Z  N  C  V  VT ST I
//         ?  ?  ?  ?  ^  -  -
//
static inline void instr_divb_direct(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int8_t) read_8(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    int32_t op1   = (int32_t) (int16_t) read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divb_immediate(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int8_t) read_8(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    int32_t op1   = (int32_t) (int16_t) read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divb_indirect(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int8_t) read_8(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    int32_t op1   = (int32_t) (int16_t) read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}

static inline void instr_divb_indexed(cpu_context * cc, uint32_t opcode)
{
    int32_t op2   = (int32_t) (int8_t) read_8(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    int32_t op1   = (int32_t) (int16_t) read_16(cc, wreg);

    write_8(cc, wreg, op1 / op2);
    write_8(cc, wreg + 1, op1 % op2);
}
