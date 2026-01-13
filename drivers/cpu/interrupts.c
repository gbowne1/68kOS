/*
 * drivers/cpu/interrupts.c
 * Interrupt management for MC68000
 */

#include <drivers/cpu/cpu.h>
#include <drivers/char.h>

/* * Sets the interrupt mask level (0-7).
 * Level 7 is non-maskable. 
 * Level 0 enables all interrupts.
 */
void cpu_set_interrupt_level(uint8_t level) {
    if (level > 7) level = 7;

    /* Shift level to bits 8-10 of the Status Register */
    uint16_t mask = (uint16_t)level << 8;
    
    __asm__ __volatile__ (
        "move.w %sr, %%d0\n"      /* Get current SR */
        "andi.w #0xf8ff, %%d0\n"  /* Clear existing mask bits */
        "or.w %0, %%d0\n"         /* Insert new mask */
        "move.w %%d0, %sr\n"      /* Write back to SR */
        :
        : "d"(mask)
        : "d0"
    );
}

void interrupts_init(void) {
    /* Set mask to 0 to allow all hardware interrupts */
    cpu_set_interrupt_level(0);
    serial_puts("CPU Interrupt masking initialized to Level 0.\n");
}

/* End of file */
