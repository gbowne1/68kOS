/*
 * drivers/cpu/cpu.h
 * Processor abstraction for MC68000
 */

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

/* Force inline assembly for performance */
static inline void cpu_halt(void) {
    __asm__ __volatile__ ("stop #0x2700");
}

static inline void cpu_enable_interrupts(void) {
    __asm__ __volatile__ ("and.w #0xf8ff, %sr");
}

static inline void cpu_disable_interrupts(void) {
    __asm__ __volatile__ ("or.w #0x0700, %sr");
}

#endif

/* End of file */
