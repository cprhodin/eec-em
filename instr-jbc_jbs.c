
// Jump to location at signed 8-bit offset if bit 0 is clear
//  opcode: 0x30
//  flags:
//
static inline void instr_jbc_b0(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 0) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 1 is clear
//  opcode: 0x31
//  flags:
//
static inline void instr_jbc_b1(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 1) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 2 is clear
//  opcode: 0x32
//  flags:
//
static inline void instr_jbc_b2(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 2) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 3 is clear
//  opcode: 0x33
//  flags:
//
static inline void instr_jbc_b3(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 3) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 4 is clear
//  opcode: 0x34
//  flags:
//
static inline void instr_jbc_b4(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 4) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 5 is clear
//  opcode: 0x35
//  flags:
//
static inline void instr_jbc_b5(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 5) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 6 is clear
//  opcode: 0x36
//  flags:
//
static inline void instr_jbc_b6(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 6) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 7 is clear
//  opcode: 0x37
//  flags:
//
static inline void instr_jbc_b7(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 7) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 0 is set
//  opcode: 0x38
//  flags:
//
static inline void instr_jbs_b0(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 0) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 1 is set
//  opcode: 0x39
//  flags:
//
static inline void instr_jbs_b1(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 1) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 2 is set
//  opcode: 0x3A
//  flags:
//
static inline void instr_jbs_b2(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 2) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 3 is set
//  opcode: 0x3B
//  flags:
//
static inline void instr_jbs_b3(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 3) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 4 is set
//  opcode: 0x3C
//  flags:
//
static inline void instr_jbs_b4(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 4) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 5 is set
//  opcode: 0x3D
//  flags:
//
static inline void instr_jbs_b5(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 5) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset if bit 6 is set
//  opcode: 0x3E
//  flags:
//
static inline void instr_jbs_b6(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 6) & read_8(cc, reg))) rjump_8(cc, offset);
}

// Jump to location at signed 8-bit offset aif bit 7 is set
//  opcode: 0x3F
//  flags:
//
static inline void instr_jbs_b7(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);

    if (!((0x1 << 7) & read_8(cc, reg))) rjump_8(cc, offset);
}
