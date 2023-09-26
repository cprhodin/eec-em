
static inline void instr_je(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fZERO & cc->status) rjump_8(cc, offset);
}

static inline void instr_jne(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fZERO & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jlt(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fNEGATIVE & cc->status) rjump_8(cc, offset);
}

static inline void instr_jge(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fNEGATIVE & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jc(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fCARRY & cc->status) rjump_8(cc, offset);
}

static inline void instr_jnc(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fCARRY & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jv(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fOVERFLOW & cc->status) rjump_8(cc, offset);
}

static inline void instr_jnv(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fOVERFLOW & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jvt(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fOVERFLOWTRAP & cc->status) rjump_8(cc, offset);
    CLR_STATUS(cc, fOVERFLOWTRAP);
}

static inline void instr_jnvt(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fOVERFLOWTRAP & cc->status)) rjump_8(cc, offset);
    CLR_STATUS(cc, fOVERFLOWTRAP);
}

static inline void instr_jst(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fSTICKY & cc->status) rjump_8(cc, offset);
}

static inline void instr_jnst(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fSTICKY & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jgt(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!((fNEGATIVE | fZERO) & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jle(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if ((fNEGATIVE | fZERO) & cc->status) rjump_8(cc, offset);
}

static inline void instr_jh(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (fCARRY == ((fCARRY | fZERO) & cc->status)) rjump_8(cc, offset);
}

static inline void instr_jnh(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    if (!(fCARRY & cc->status) || (fZERO & cc->status)) rjump_8(cc, offset);
}

