
// Jump to location at signed 11-bit offset
//  opcode: 0xC8
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_sjmp_0x000(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x000 + offset);
}

static inline void instr_sjmp_0x100(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x100 + offset);
}

static inline void instr_sjmp_0x200(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x200 + offset);
}

static inline void instr_sjmp_0x300(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x300 + offset);
}

static inline void instr_sjmp_0x400(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x400 + offset);
}

static inline void instr_sjmp_0x500(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x500 + offset);
}

static inline void instr_sjmp_0x600(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x600 + offset);
}

static inline void instr_sjmp_0x700(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    rjump_11(cc, 0x700 + offset);
}

// Call location at signed 11-bit offset
//  opcode: 0xC8
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_scall_0x000(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x000 + offset);
}

static inline void instr_scall_0x100(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x100 + offset);
}

static inline void instr_scall_0x200(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x200 + offset);
}

static inline void instr_scall_0x300(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x300 + offset);
}

static inline void instr_scall_0x400(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x400 + offset);
}

static inline void instr_scall_0x500(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x500 + offset);
}

static inline void instr_scall_0x600(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x600 + offset);
}

static inline void instr_scall_0x700(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset = fetch(cc);

    push(cc, get_pc(cc));
    rjump_11(cc, 0x700 + offset);
}
