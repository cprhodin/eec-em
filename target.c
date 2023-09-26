

// addressable target memory
uint8_t tgt_memory[65536];

uint8_t tgt_read(uint address)
{
    address &= 0xffff;
    return tgt_memory[address];
}

void tgt_write(uint address, uint8_t data)
{
    address &= 0xffff;
    tgt_memory[address] = data;
}

// register

    uint8_t  b[256];
    uint16_t w[128];
    uint32_t l[64];


typedef struct {
	uint8_t byte;
} target_memory;


typedef struct {
	uint32_t program_counter;
	uint16_t processor_status_word;
	target_memory memory;
} target;
