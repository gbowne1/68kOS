/*
 * boot/vectors.S
 * M68K Vector Table
 */

.section .vectors
.long _stack_top       /* 0x00: Initial Stack Pointer */
.long _start           /* 0x04: Initial Program Counter (Reset) */

/* Fill the rest of the first 256 bytes with a dummy handler */
.rept 62
    .long dummy_handler
.endr

.section .text
dummy_handler:
    rte                /* Return from Exception */

/* End of file */
