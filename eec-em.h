#ifndef _EEC_EM_H
#define _EEC_EM_H

typedef struct {
    uint16_t pc;
    uint16_t ipc;
} target_state;

extern int invalid_instruction(target_state * cpu, uint8_t opcode);
extern int prefixed_instruction_fetch(target_state * cpu, uint8_t opcode);

#endif // _EEC_EM_H
