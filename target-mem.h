#ifndef _TARGET_MEM_H
#define _TARGET_MEM_H

typedef struct {
	uint8_t byte;
} target_memory;

union {
	uint8_t b;
	uint16_t w;
	uint32_t l;
};

#endif // _TARGET_MEM_H
