
static inline void instr_add_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_add_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_add_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_add_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addb_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_direct(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 + op2);
}

static inline void instr_addb_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_immediate(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 + op2);
}

static inline void instr_addb_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indirect(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 + op2);
}

static inline void instr_addb_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indexed(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 + op2);
}

static inline void instr_sub_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_sub_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_sub_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_sub_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subb_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_direct(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_subb_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_immediate(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_subb_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indirect(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_subb_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indexed(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_addc_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addc_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addc_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addc_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addcb_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addcb_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addcb_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_addcb_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 + op2);
}

static inline void instr_subc_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subc_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subc_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subc_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subcb_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subcb_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subcb_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_subcb_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_cmp_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_direct(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_cmp_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_immediate(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_cmp_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indirect(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_cmp_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_16(cc, waop_indexed(cc));
    uint32_t wreg = fetch(cc);
    uint32_t op1  = read_16(cc, wreg);

    write_16(cc, wreg, op1 - op2);
}

static inline void instr_cmpb_direct(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_direct(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_cmpb_immediate(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_immediate(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_cmpb_indirect(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indirect(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}

static inline void instr_cmpb_indexed(cpu_context * cc, uint32_t opcode)
{
    uint32_t op2  = read_8(cc, baop_indexed(cc));
    uint32_t breg = fetch(cc);
    uint32_t op1  = read_8(cc, breg);

    write_8(cc, breg, op1 - op2);
}
