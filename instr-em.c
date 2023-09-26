#include <stdint.h>

#include "eec-em.h"
#include "instr-tab.h"

#define

int instr_add2(target_state * cpu, uint8_t opcode)
{
    int rc;
    int mode = opcode & 0x3;

    switch (mode)
    {
    case 0:
        // direct
        waop = get_bitfield(cpu->pc, 8, 8);
        wreg = get_bitfield(cpu->pc, 16, 8);
        break;

    case 1:
        // immediate
        waop =  get_bitfield(cpu->pc, 8, 8)
             | (get_bitfield(cpu->pc, 16, 8) << 8);
        wreg = get_bitfield(cpu->pc, 24, 8);
        break;

    case 2:
        // indirect
        waop = get_bitfield(cpu->pc, 8, 8);
        wreg = get_bitfield(cpu->pc, 24, 8);
        break;

    case 3:
        // indexed
        break;
    }

    return rc;
}

int instr_add3(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_addb2(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_addb3(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_addc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_addcb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_and(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_andb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_clr(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_clrb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_clrc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_clrvt(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_cmp(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_cmpb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_dec(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_decb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_di(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_div(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_divb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_divu(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_divub(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_djnz(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ei(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ext(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_extb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_inc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_incb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jbc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jbs(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_je(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jge(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jgt(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jh(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jle(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jlt(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jnc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jne(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jnh(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jnst(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jnv(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jnvt(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jst(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jv(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_jvt(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_lcall(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ld(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ldb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ldbse(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ldbze(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ljmp(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_mul(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_mulb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_mulu(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_mulub(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_neg(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_negb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_nop(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_norml(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_not(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_notb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_or(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_orb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_pop(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_popf(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_push(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_pushf(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_ret(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_reti(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_scall(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_setc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shl(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shlb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shll(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shr(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shra(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shrab(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shral(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shrb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_shrl(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

void instr_sjmp000(void)
{
    pc += 0x000 + *pc++;
}

void instr_sjmp100(void)
{
    pc += 0x100 + *pc++;
}

void instr_sjmp200(void)
{
    pc += 0x200 + *pc++;
}

void instr_sjmp300(void)
{
    pc += 0x300 + *pc++;
}

void instr_sjmp400(void)
{
    pc += 0x400 + *pc++;
}

void instr_sjmp500(void)
{
    pc += 0x500 + *pc++;
}

void instr_sjmp600(void)
{
    pc += 0x600 + *pc++;
}

void instr_sjmp700(void)
{
    pc += 0x700 + *pc++;
}

int instr_skip(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_st(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_stb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_sub(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_subb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_subc(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_subcb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_trap(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_xor(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}

int instr_xorb(target_state * cpu, uint8_t opcode)
{
    int rc;

    return rc;
}
