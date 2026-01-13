/*
 * drivers/char/timer.c
 * Generic Timer Setup
 */

#include <stdint.h>
#include <drivers/cpu.h>

void timer_init(uint32_t frequency) {
    /* * On a real 68k board, you would write to the Timer 
     * Control Register here. For QEMU's q800, we assume 
     * the system clock is already running.
     */
     
    serial_puts("Timer initialized.\n");
}

/* End of file */
