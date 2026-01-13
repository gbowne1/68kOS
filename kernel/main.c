/*
 * kernel/main.c
 */

#include <kernel/mm.h>
#include <kernel/syscalls.h>
#include <drivers/char.h>
#include <drivers/cpu.h>

void kmain(void) {
    /* Initialize Serial for debug output */
    serial_puts("Booting MC68000 OS...\n");

    /* Setup Memory Management */
    mm_init();
    serial_puts("Memory Manager Initialized.\n");

    /* Enable Interrupts on the CPU */
    cpu_enable_interrupts();
    serial_puts("Interrupts Enabled. Kernel ready.\n");

    for (;;) {
        /* Main Kernel Loop */
    }
}

/* End of file */
