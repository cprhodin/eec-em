
static inline void instr_add3_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_direct(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 + op3);
}

static inline void instr_add3_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_immediate(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 + op3);
}

static inline void instr_add3_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_indirect(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 + op3);
}

static inline void instr_add3_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_indexed(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 + op3);
}

static inline void instr_sub3_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_direct(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 - op3);
}

static inline void instr_sub3_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_immediate(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 - op3);
}

static inline void instr_sub3_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_indirect(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 - op3);
}

static inline void instr_sub3_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_16(cc, waop_indexed(cc));
    uint32_t op2   = read_16(cc, fetch(cc));
    uint32_t wreg1 = fetch(cc);

    write_16(cc, wreg1, op2 - op3);
}

static inline void instr_addb3_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_direct(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 + op3);
}

static inline void instr_addb3_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_immediate(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 + op3);
}

static inline void instr_addb3_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_indirect(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 + op3);
}

static inline void instr_addb3_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_indexed(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 + op3);
}


static inline void instr_subb3_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_direct(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 - op3);
}

static inline void instr_subb3_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_immediate(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 - op3);
}

static inline void instr_subb3_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_indirect(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 - op3);
}

static inline void instr_subb3_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op3   = read_8(cc, baop_indexed(cc));
    uint32_t op2   = read_8(cc, fetch(cc));
    uint32_t breg1 = fetch(cc);

    write_8(cc, breg1, op2 - op3);
}
