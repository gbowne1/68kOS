/* linker.ld */
ENTRY(_start)

MEMORY
{
    /* Defining a 128KB block for the base system */
    ram (rwx) : ORIGIN = 0x000000, LENGTH = 128K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.vectors))    /* Vector table MUST be at 0x0 */
        *(.text*)            /* Code */
        *(.rodata*)          /* Read-only data */
    } > ram

    .data :
    {
        *(.data*)            /* Initialized data */
    } > ram

    .bss :
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > ram

    _stack_top = ORIGIN(ram) + LENGTH(ram);
}
