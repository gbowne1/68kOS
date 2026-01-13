/*
 * boot/am-interrupts.S
 * Low-level Interrupt Service Routines
 */

.section .text
.global timer_isr
.extern schedule

timer_isr:
    /* 1. Save all registers to the stack (Context Save) */
    movem.l %d0-%d7/%a0-%a6, -(%sp)

    /* 2. Call the C scheduler to pick the next task */
    jsr schedule

    /* 3. Restore registers (Context Restore) */
    movem.l (%sp)+, %d0-%d7/%a0-%a6

    /* 4. Return from Exception */
    rte

/* End of file */
