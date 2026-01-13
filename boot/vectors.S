/*
 * boot/vectors.S
 * Complete M68K Vector Table for Kernel and Userland
 */

.section .vectors

/* 0x00: Standard Exception Vectors */
.long _stack_top           /* Initial Stack Pointer */
.long _start               /* Initial Program Counter (Reset) */

/* * The 68000 uses vectors 2-23 for internal exceptions (Bus Error, etc).
 * We fill these with the dummy_handler for now.
 */
.rept 22
    .long dummy_handler
.endr

/* * 0x64: Level 1 Interrupt (Autovector)
 * Used by our system timer for multitasking.
 */
.org 0x64
.long timer_isr

/* * Fill the space between Level 1 and the Traps.
 */
.org 0x68
.rept 6
    .long dummy_handler
.endr

/* * 0x80: TRAP #0 Vector
 * This is the entry point for Userland System Calls.
 */
.org 0x80
.long syscall_asm_entry

/* * Fill the remainder of the 256-byte vector table (up to vector 255).
 * 0x400 is the size of the full table (256 vectors * 4 bytes).
 */
.org 0x400

.section .text

/* * Default handler for unimplemented interrupts.
 * Simply returns to the previous state.
 */
dummy_handler:
    rte

/* End of file */
