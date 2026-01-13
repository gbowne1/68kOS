/*
 * boot/boot.S
 * Low-level initialization
 */

.section .text
.global _start
.extern kmain
.extern _bss_start
.extern _bss_end

_start:
    /* Disable interrupts */
    move.w #0x2700, %sr

    /* Clear BSS section for C99 compliance */
    lea _bss_start, %a0
    lea _bss_end, %a1

clear_bss:
    cmpa.l %a0, %a1
    beq jump_to_main
    clr.b (%a0)+
    bra clear_bss

jump_to_main:
    /* Call the C kernel entry point */
    jsr kmain

    /* If kmain returns, halt the CPU */
stop_cpu:
    stop #0x2700
    bra stop_cpu

/* End of file */
