#include <stdint.h>
#include <stdio.h>

#include "i8061.h"
#include "instr-tab.h"

#define ASSERT(a)

typedef unsigned int uint_t;

typedef void (* instr_func_t)(cpu_context * cc, uint32_t opcode);

// Status Bit Masks
#define fSTICKY       (0x01)
#define fINTERRUPTEN  (0x02)
#define fNA           (0x04)
#define fCARRY        (0x08)
#define fOVERFLOWTRAP (0x10)
#define fOVERFLOW     (0x20)
#define fNEGATIVE     (0x40)
#define fZERO         (0x80)

#define CLR_STATUS(cc,bits) do { (cc)->status = (cc)->status & ~bits; } while (0)
#define SET_STATUS(cc,bits) do { (cc)->status = (cc)->status |  bits; } while (0)

static inline void rjump_8(cpu_context * cc, int32_t offset)
{
    // sign extend the offset from 8 to 32 bits
    offset = (offset << 24) >> 24;

    cc->pc += offset;
}

static inline void rjump_11(cpu_context * cc, int32_t offset)
{
    // sign extend the offset from 11 to 32 bits
    offset = (offset << 21) >> 21;

    cc->pc += offset;
}

static inline void rjump_16(cpu_context * cc, int32_t offset)
{
    // sign extend the offset from 16 to 32 bits
    offset = (offset << 16) >> 16;

    cc->pc += offset;
}

static inline uint32_t get_pc(cpu_context * cc)
{
    return cc->pc - cc->target_memory;
}

static inline void set_pc(cpu_context * cc, uint32_t data)
{
    cc->pc = data + cc->target_memory;
}

#include "read_write.c"

// Set the CPU context to the reset state
//
void reset(cpu_context * cc)
{
    write_8(cc, LSO_DATA,  0x00);
    write_8(cc, BIDIR_IO,  0xFC);
    write_8(cc, IO_STATUS, 0xC8);
    write_8(cc, HSI_MASK,  0x00);
    write_16(cc, IO_TIMER,  0x0000);

    cc->status = 0x7F;
    set_pc(cc, 0x2000);
}

#include "baop_waop.c"
#include "instr-jcc.c"
#include "instr-unary_op.c"
#include "instr-logical.c"
#include "instr-binary_op.c"
#include "instr-trinary_op.c"
#include "instr-push_pop.c"
#include "instr-shr_shl.c"
#include "instr-sjmp_scall.c"
#include "instr-jbc_jbs.c"
#include "instr-load_store.c"
#include "instr-mul_div.c"

// Invalid Instruction
//  opcode: many
//
static inline void invalid_instruction(cpu_context * cc, uint32_t opcode)
{
}

// One byte NOP
//  opcode: 0xFF
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_nop(cpu_context * cc, uint32_t opcode)
{
}

// Two byte NOP
//  opcode: 0x00
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_skip(cpu_context * cc, uint32_t opcode)
{
    fetch(cc);
}

// One byte DJNZ
//  opcode: 0xE0
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_djnz(cpu_context * cc, uint32_t opcode)
{
    uint32_t reg = fetch(cc);
    uint32_t offset = fetch(cc);
    uint32_t data;

    data = read_8(cc, reg);
    data = data - 1;
    write_8(cc, reg, data);

    if (0 != data) rjump_8(cc, offset);
}

// One byte LJMP
//  opcode: 0xE7
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ljmp(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset;

    offset  = fetch(cc);
    offset |= fetch(cc) << 8;

    rjump_16(cc, offset);
}

// One byte LCALL
//  opcode: 0xEF
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_lcall(cpu_context * cc, uint32_t opcode)
{
    uint32_t offset;

    offset  = fetch(cc);
    offset |= fetch(cc) << 8;

    push(cc, get_pc(cc));
    rjump_16(cc, offset);
}

// One byte RET
//  opcode: 0xF0
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_ret(cpu_context * cc, uint32_t opcode)
{
    set_pc(cc, pop(cc));
}

// One byte RETI
//  opcode: 0xF1
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_reti(cpu_context * cc, uint32_t opcode)
{
}

// One byte TRAP
//  opcode: 0xF7
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  -
//
static inline void instr_trap(cpu_context * cc, uint32_t opcode)
{

}

// One byte CLRC
//  opcode: 0xF8
//  flags: Z  N  C  V  VT ST I
//         -  -  0  -  -  -  -
//
static inline void instr_clrc(cpu_context * cc, uint32_t opcode)
{
    CLR_STATUS(cc, fCARRY);
}

// One byte SETC
//  opcode: 0xF9
//  flags: Z  N  C  V  VT ST I
//         -  -  1  -  -  -  -
//
static inline void instr_setc(cpu_context * cc, uint32_t opcode)
{
    SET_STATUS(cc, fCARRY);
}

// One byte DI
//  opcode: 0xFA
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  0
//
static inline void instr_di(cpu_context * cc, uint32_t opcode)
{
    CLR_STATUS(cc, fINTERRUPTEN);
}

// One byte EI
//  opcode: 0xFB
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  -  -  1
//
static inline void instr_ei(cpu_context * cc, uint32_t opcode)
{
    SET_STATUS(cc, fINTERRUPTEN);
}

// One byte CLRVT
//  opcode: 0xFC
//  flags: Z  N  C  V  VT ST I
//         -  -  -  -  0  -  -
//
static inline void instr_clrvt(cpu_context * cc, uint32_t opcode)
{
    CLR_STATUS(cc, fOVERFLOWTRAP);
}

static inline void instr_norml(cpu_context * cc, uint32_t opcode)
{
    uint32_t breg = fetch(cc);
    uint32_t lreg = fetch(cc);
    int32_t data;

    data = (int32_t) read_32(cc, lreg);

    write_32(cc, lreg, data);

    CLR_STATUS(cc, fZERO | fNEGATIVE | fCARRY);
    SET_STATUS(cc, ((0 == data) ? fZERO         : 0) |
               ((0 >  data) ? fNEGATIVE     : 0)   );
}

instr_func_t i8061_prefixed_instruction_set[256] =
{
    [0x00 ... 0x4b] = invalid_instruction,
    [0x4c]          = instr_mul3,
    [0x4d]          = instr_mul3,
    [0x4e]          = instr_mul3,
    [0x4f]          = instr_mul3,
    [0x50 ... 0x5b] = invalid_instruction,
    [0x5c]          = instr_mulb3,
    [0x5d]          = instr_mulb3,
    [0x5e]          = instr_mulb3,
    [0x5f]          = instr_mulb3,
    [0x60 ... 0x6b] = invalid_instruction,
    [0x6c]          = instr_mul,
    [0x6d]          = instr_mul,
    [0x6e]          = instr_mul,
    [0x6f]          = instr_mul,
    [0x70 ... 0x7b] = invalid_instruction,
    [0x7c]          = instr_mulb,
    [0x7d]          = instr_mulb,
    [0x7e]          = instr_mulb,
    [0x7f]          = instr_mulb,
    [0x80 ... 0x8b] = invalid_instruction,
    [0x8c]          = instr_div_direct,
    [0x8d]          = instr_div_immediate,
    [0x8e]          = instr_div_indirect,
    [0x8f]          = instr_div_indexed,
    [0x90 ... 0x9b] = invalid_instruction,
    [0x9c]          = instr_divb_direct,
    [0x9d]          = instr_divb_immediate,
    [0x9e]          = instr_divb_indirect,
    [0x9f]          = instr_divb_indexed,
    [0xa0 ... 0xff] = invalid_instruction,
};

static inline void prefixed_instruction_fetch(cpu_context * cc, uint32_t opcode)
{
    opcode = fetch(cc);

    i8061_prefixed_instruction_set[opcode](cc, opcode);
}

instr_func_t i8061_instruction_set[256] =
{
    [0x00]          = instr_skip,
    [0x01]          = instr_clr,
    [0x02]          = instr_not,
    [0x03]          = instr_neg,
    [0x04]          = invalid_instruction,
    [0x05]          = instr_dec,
    [0x06]          = instr_ext,
    [0x07]          = instr_inc,
    [0x08]          = instr_shr,
    [0x09]          = instr_shl,
    [0x0a]          = instr_shra,
    [0x0b]          = invalid_instruction,
    [0x0c]          = instr_shrl,
    [0x0d]          = instr_shll,
    [0x0e]          = instr_shral,
    [0x0f]          = instr_norml,
    [0x10]          = invalid_instruction,
    [0x11]          = instr_clrb,
    [0x12]          = instr_notb,
    [0x13]          = instr_negb,
    [0x14]          = invalid_instruction,
    [0x15]          = instr_decb,
    [0x16]          = instr_extb,
    [0x17]          = instr_incb,
    [0x18]          = instr_shrb,
    [0x19]          = instr_shlb,
    [0x1a]          = instr_shrab,
    [0x1b ... 0x1f] = invalid_instruction,
    [0x20]          = instr_sjmp_0x000,
    [0x21]          = instr_sjmp_0x100,
    [0x22]          = instr_sjmp_0x200,
    [0x23]          = instr_sjmp_0x300,
    [0x24]          = instr_sjmp_0x400,
    [0x25]          = instr_sjmp_0x500,
    [0x26]          = instr_sjmp_0x600,
    [0x27]          = instr_sjmp_0x700,
    [0x28]          = instr_scall_0x000,
    [0x29]          = instr_scall_0x100,
    [0x2a]          = instr_scall_0x200,
    [0x2b]          = instr_scall_0x300,
    [0x2c]          = instr_scall_0x400,
    [0x2d]          = instr_scall_0x500,
    [0x2e]          = instr_scall_0x600,
    [0x2f]          = instr_scall_0x700,
    [0x30]          = instr_jbc_b0,
    [0x31]          = instr_jbc_b1,
    [0x32]          = instr_jbc_b2,
    [0x33]          = instr_jbc_b3,
    [0x34]          = instr_jbc_b4,
    [0x35]          = instr_jbc_b5,
    [0x36]          = instr_jbc_b6,
    [0x37]          = instr_jbc_b7,
    [0x38]          = instr_jbs_b0,
    [0x39]          = instr_jbs_b1,
    [0x3a]          = instr_jbs_b2,
    [0x3b]          = instr_jbs_b3,
    [0x3c]          = instr_jbs_b4,
    [0x3d]          = instr_jbs_b5,
    [0x3e]          = instr_jbs_b6,
    [0x3f]          = instr_jbs_b7,
    [0x40]          = instr_and3,
    [0x41]          = instr_and3,
    [0x42]          = instr_and3,
    [0x43]          = instr_and3,
    [0x44]          = instr_add3_direct,
    [0x45]          = instr_add3_immediate,
    [0x46]          = instr_add3_indirect,
    [0x47]          = instr_add3_indexed,
    [0x48]          = instr_sub3_direct,
    [0x49]          = instr_sub3_immediate,
    [0x4a]          = instr_sub3_indirect,
    [0x4b]          = instr_sub3_indexed,
    [0x4c]          = instr_mulu3,
    [0x4d]          = instr_mulu3,
    [0x4e]          = instr_mulu3,
    [0x4f]          = instr_mulu3,
    [0x50]          = instr_andb3,
    [0x51]          = instr_andb3,
    [0x52]          = instr_andb3,
    [0x53]          = instr_andb3,
    [0x54]          = instr_addb3_direct,
    [0x55]          = instr_addb3_immediate,
    [0x56]          = instr_addb3_indirect,
    [0x57]          = instr_addb3_indexed,
    [0x58]          = instr_subb3_direct,
    [0x59]          = instr_subb3_immediate,
    [0x5a]          = instr_subb3_indirect,
    [0x5b]          = instr_subb3_indexed,
    [0x5c]          = instr_mulub3,
    [0x5d]          = instr_mulub3,
    [0x5e]          = instr_mulub3,
    [0x5f]          = instr_mulub3,
    [0x60]          = instr_and,
    [0x61]          = instr_and,
    [0x62]          = instr_and,
    [0x63]          = instr_and,
    [0x64]          = instr_add_direct,
    [0x65]          = instr_add_immediate,
    [0x66]          = instr_add_indirect,
    [0x67]          = instr_add_indexed,
    [0x68]          = instr_sub_direct,
    [0x69]          = instr_sub_immediate,
    [0x6a]          = instr_sub_indirect,
    [0x6b]          = instr_sub_indexed,
    [0x6c]          = instr_mulu,
    [0x6d]          = instr_mulu,
    [0x6e]          = instr_mulu,
    [0x6f]          = instr_mulu,
    [0x70]          = instr_andb,
    [0x71]          = instr_andb,
    [0x72]          = instr_andb,
    [0x73]          = instr_andb,
    [0x74]          = instr_addb_direct,
    [0x75]          = instr_addb_immediate,
    [0x76]          = instr_addb_indirect,
    [0x77]          = instr_addb_indexed,
    [0x78]          = instr_subb_direct,
    [0x79]          = instr_subb_immediate,
    [0x7a]          = instr_subb_indirect,
    [0x7b]          = instr_subb_indexed,
    [0x7c]          = instr_mulub,
    [0x7d]          = instr_mulub,
    [0x7e]          = instr_mulub,
    [0x7f]          = instr_mulub,
    [0x80]          = instr_or,
    [0x81]          = instr_or,
    [0x82]          = instr_or,
    [0x83]          = instr_or,
    [0x84]          = instr_xor,
    [0x85]          = instr_xor,
    [0x86]          = instr_xor,
    [0x87]          = instr_xor,
    [0x88]          = instr_cmp_direct,
    [0x89]          = instr_cmp_immediate,
    [0x8a]          = instr_cmp_indirect,
    [0x8b]          = instr_cmp_indexed,
    [0x8c]          = instr_divu_direct,
    [0x8d]          = instr_divu_immediate,
    [0x8e]          = instr_divu_indirect,
    [0x8f]          = instr_divu_indexed,
    [0x90]          = instr_orb,
    [0x91]          = instr_orb,
    [0x92]          = instr_orb,
    [0x93]          = instr_orb,
    [0x94]          = instr_xorb_direct,
    [0x95]          = instr_xorb_immediate,
    [0x96]          = instr_xorb_indirect,
    [0x97]          = instr_xorb_indexed,
    [0x98]          = instr_cmpb_direct,
    [0x99]          = instr_cmpb_immediate,
    [0x9a]          = instr_cmpb_indirect,
    [0x9b]          = instr_cmpb_indexed,
    [0x9c]          = instr_divub_direct,
    [0x9d]          = instr_divub_immediate,
    [0x9e]          = instr_divub_indirect,
    [0x9f]          = instr_divub_indexed,
    [0xa0]          = instr_ld,
    [0xa1]          = instr_ld,
    [0xa2]          = instr_ld,
    [0xa3]          = instr_ld,
    [0xa4]          = instr_addc_direct,
    [0xa5]          = instr_addc_immediate,
    [0xa6]          = instr_addc_indirect,
    [0xa7]          = instr_addc_indexed,
    [0xa8]          = instr_subc_direct,
    [0xa9]          = instr_subc_immediate,
    [0xaa]          = instr_subc_indirect,
    [0xab]          = instr_subc_indexed,
    [0xac]          = instr_ldbze,
    [0xad]          = instr_ldbze,
    [0xae]          = instr_ldbze,
    [0xaf]          = instr_ldbze,
    [0xb0]          = instr_ldb,
    [0xb1]          = instr_ldb,
    [0xb2]          = instr_ldb,
    [0xb3]          = instr_ldb,
    [0xb4]          = instr_addcb_direct,
    [0xb5]          = instr_addcb_immediate,
    [0xb6]          = instr_addcb_indirect,
    [0xb7]          = instr_addcb_indexed,
    [0xb8]          = instr_subcb_direct,
    [0xb9]          = instr_subcb_immediate,
    [0xba]          = instr_subcb_indirect,
    [0xbb]          = instr_subcb_indexed,
    [0xbc]          = instr_ldbse,
    [0xbd]          = instr_ldbse,
    [0xbe]          = instr_ldbse,
    [0xbf]          = instr_ldbse,
    [0xc0]          = instr_st,
    [0xc1]          = invalid_instruction,
    [0xc2]          = instr_st,
    [0xc3]          = instr_st,
    [0xc4]          = instr_stb,
    [0xc5]          = invalid_instruction,
    [0xc6]          = instr_stb,
    [0xc7]          = instr_stb,
    [0xc8]          = instr_push,
    [0xc9]          = instr_push,
    [0xca]          = instr_push,
    [0xcb]          = instr_push,
    [0xcc]          = instr_pop,
    [0xcd]          = invalid_instruction,
    [0xce]          = instr_pop,
    [0xcf]          = instr_pop,
    [0xd0]          = instr_jnst,
    [0xd1]          = instr_jnh,
    [0xd2]          = instr_jgt,
    [0xd3]          = instr_jnc,
    [0xd4]          = instr_jnvt,
    [0xd5]          = instr_jnv,
    [0xd6]          = instr_jge,
    [0xd7]          = instr_jne,
    [0xd8]          = instr_jst,
    [0xd9]          = instr_jh,
    [0xda]          = instr_jle,
    [0xdb]          = instr_jc,
    [0xdc]          = instr_jvt,
    [0xdd]          = instr_jv,
    [0xde]          = instr_jlt,
    [0xdf]          = instr_je,
    [0xe0]          = instr_djnz,
    [0xe1 ... 0xe6] = invalid_instruction,
    [0xe7]          = instr_ljmp,
    [0xe8 ... 0xee] = invalid_instruction,
    [0xef]          = instr_lcall,
    [0xf0]          = instr_ret,
    [0xf1]          = instr_reti,
    [0xf2]          = instr_pushf,
    [0xf3]          = instr_popf,
    [0xf4 ... 0xf6] = invalid_instruction,
    [0xf7]          = instr_trap,
    [0xf8]          = instr_clrc,
    [0xf9]          = instr_setc,
    [0xfa]          = instr_di,
    [0xfb]          = instr_ei,
    [0xfc]          = instr_clrvt,
    [0xfd]          = invalid_instruction,
    [0xfe]          = prefixed_instruction_fetch,
    [0xff]          = instr_nop,
};


void execute(cpu_context * cc)
{
    uint8_t opcode;

    opcode = fetch(cc);

    i8061_instruction_set[opcode](cc, opcode);
}
