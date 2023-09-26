
static inline uint32_t baop_direct(cpu_context * cc)
{
    uint32_t addr = fetch(cc);

    return addr;
}

static inline uint32_t waop_direct(cpu_context * cc)
{
    uint32_t addr = fetch(cc);

    ASSERT((addr & 0x01) == 0);

    return addr;
}

static inline uint32_t baop_immediate(cpu_context * cc)
{
#if 0
    uint32_t addr;

    addr = get_pc(cc);
    set_pc(cc, addr + 1);

    return addr;
#else
    uint8_t * target_memory;
    uint8_t * pc;
    uint32_t  addr;

    target_memory = cc->target_memory;
    pc = cc->pc;

    cc->pc = pc + 1;

    addr = pc - target_memory;

    return addr;
#endif
}

static inline uint32_t waop_immediate(cpu_context * cc)
{
#if 1
    uint32_t addr;

    addr = get_pc(cc);
    set_pc(cc, addr + 2);

    return addr;
#else
    uint8_t * target_memory;
    uint8_t * pc;
    uint32_t  addr;

    target_memory = cc->target_memory;
    pc = cc->pc;

    cc->pc = pc + 2;

    addr = pc - target_memory;

    return addr;
#endif
}

static inline uint32_t baop_indirect(cpu_context * cc)
{
    uint32_t wreg = fetch(cc);
    uint32_t addr;

    addr = read_16(cc, 0xFE & wreg);

    if (0x01 & wreg) write_16(cc, 0xFE & wreg, addr + 1);

    return addr;
}

static inline uint32_t waop_indirect(cpu_context * cc)
{
    uint32_t wreg = fetch(cc);
    uint32_t addr;

    addr = read_16(cc, 0xFE & wreg);

    ASSERT((addr & 0x0001) == 0);

    if (0x01 & wreg) write_16(cc, 0xFE & wreg, addr + 2);

    return addr;
}

static inline uint32_t baop_indexed(cpu_context * cc)
{
#if 0
    uint32_t wreg = fetch(cc);
    uint32_t addr;

    if (0x01 & wreg)
    {
        addr  = fetch(cc);
        addr += fetch(cc) << 8;
    }
    else
    {
        addr  = fetch(cc);
    }

    addr += read_16(cc, 0xFE & wreg);
#else
    uint8_t * pc;
    uint32_t  addr;
    uint32_t  wreg;

    pc = cc->pc;

    wreg = *pc++;

    addr = read_16(cc, 0xFE & wreg);

    addr += *pc++;

    if (0x01 & wreg)
    {
        addr += *pc++ << 8;
    }

    cc->pc = pc;
#endif

    return addr;
}

static inline uint32_t waop_indexed(cpu_context * cc)
{
    uint32_t wreg = fetch(cc);
    uint32_t addr;

    if (0x01 & wreg)
    {
        addr  = fetch(cc);
        addr += fetch(cc) << 8;
    }
    else
    {
        addr  = fetch(cc);
    }

    ASSERT((addr & 0x0001) == 0);

    addr += read_16(cc, 0xFE & wreg);

    ASSERT((addr & 0x0001) == 0);

    return addr;
}

static inline uint32_t baop(cpu_context * cc, uint32_t opcode)
{
    switch (0x03 & opcode)
    {
    case 0:
        return baop_direct(cc);

    case 1:
        return baop_immediate(cc);

    case 2:
        return baop_indirect(cc);

    case 3:
        return baop_indexed(cc);
    }
}

static inline uint32_t waop(cpu_context * cc, uint32_t opcode)
{
    switch (0x03 & opcode)
    {
    case 0:
        return waop_direct(cc);

    case 1:
        return waop_immediate(cc);

    case 2:
        return waop_indirect(cc);

    case 3:
        return waop_indexed(cc);
    }
}
