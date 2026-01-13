/*
 * boot/syscall_asm.S
 */

.section .text
.global syscall_asm_entry
.extern syscall_handler

syscall_asm_entry:
    /* Save registers */
    movem.l %d1-%d7/%a0-%a6, -(%sp)

    /* Pass D0 (syscall number) as the first argument to C */
    move.l %d0, -(%sp)
    jsr syscall_handler
    addq.l #4, %sp          /* Clean up stack */

    /* Restore registers and return */
    movem.l (%sp)+, %d1-%d7/%a0-%a6
    rte

/* End of file */
