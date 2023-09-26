
static inline uint32_t fetch(cpu_context * cc)
{
    uint32_t data;
    uint8_t * pc;

    pc = cc->pc;
    data = *pc++;
    cc->pc = pc;

    printf(" %02X", data);

    return data;
}

static inline uint32_t read_8(cpu_context * cc, uint32_t addr)
{
    uint32_t data;

    data = *(cc->target_memory + addr);

    return data;
}

static inline void write_8(cpu_context * cc, uint32_t addr, uint32_t data)
{
    *(cc->target_memory + addr) = (uint8_t) data;
}

static inline uint32_t read_16(cpu_context * cc, uint32_t addr)
{
    uint32_t data;

    ASSERT((addr & 0x01) == 0);

    data = *((uint16_t *) (cc->target_memory + addr));
    data = __builtin_bswap16(data);

    return data;
}

static inline void write_16(cpu_context * cc, uint32_t addr, uint32_t data)
{
    ASSERT((addr & 0x01) == 0);

    data = __builtin_bswap16(data);
    *((uint16_t *) (cc->target_memory + addr)) = (uint16_t) data;
}

static inline uint32_t read_32(cpu_context * cc, uint32_t addr)
{
    uint32_t data;

    ASSERT((addr & 0x03) == 0);

    data = *((uint32_t *) (cc->target_memory + addr));
    data = __builtin_bswap32(data);

    return data;
}

static inline void write_32(cpu_context * cc, uint32_t addr, uint32_t data)
{
    ASSERT((addr & 0x03) == 0);

    data = __builtin_bswap32(data);
    *((uint32_t *) (cc->target_memory + addr)) = data;
}
