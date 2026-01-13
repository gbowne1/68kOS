/*
 * kernel/main.c
 * The C entry point. Since we have no drivers yet,
 * we perform a simple infinite loop or a memory write
 * to verify the kernel is running.
 */

#include <stdint.h>

void kmain(void) {
    /* * At this stage, we have no screen or serial driver.
     * A common 'heartbeat' for 68k emulators is writing 
     * a value to a specific memory address or a 
     * known I/O port.
     */

    volatile uint32_t *heartbeat = (uint32_t *)0x40000;
    uint32_t counter = 0;

    for (;;) {
        *heartbeat = counter++;
    }
}

/* End of file */
