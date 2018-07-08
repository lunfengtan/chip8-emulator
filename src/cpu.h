#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define RAM_SIZE        4096
#define ROM_START       0x200
#define ROM_MAXSIZE     (RAM_SIZE - ROM_START)
#define STACK_SIZE      16

#define SCREEN_WIDTH    64
#define SCREEN_HEIGHT   32
#define FRAMEBUFF_SIZE  (SCREEN_WIDTH * SCREEN_HEIGHT)

typedef struct {
    uint8_t     V[16];
    uint8_t     DT;
    uint8_t     ST;

    uint16_t    PC;
    uint16_t    I;

    uint8_t     SP;
    uint16_t    stack[STACK_SIZE];

    uint8_t     ram[RAM_SIZE];

    uint8_t*    framebuff;
} Chip8CPU;

typedef union {
    uint16_t    instr;
    uint8_t     byte[2];
} opcode_t;

void cpu_init(Chip8CPU* cpu);
int load_rom(Chip8CPU* cpu, const char* file);
int disas(Chip8CPU* cpu);
void cpu_execute(Chip8CPU* cpu);

#endif
