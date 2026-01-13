/*
 * user/linker.ld
 * Linker script for user-mode applications
 */

ENTRY(main)

MEMORY
{
    /* * We define a block for the user program. 
     * Starting at 64KB (0x10000) is a safe convention.
     */
    user_ram (rwx) : ORIGIN = 0x010000, LENGTH = 128K
}

SECTIONS
{
    /* The program code */
    .text :
    {
        *(.text.main)      /* Ensure main is first if possible */
        *(.text*)
        *(.rodata*)
    } > user_ram

    /* Initialized data */
    .data :
    {
        *(.data*)
    } > user_ram

    /* Uninitialized data (cleared at load time) */
    .bss :
    {
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        _bss_end = .;
    } > user_ram

    /* * Define the user stack at the top of the assigned memory.
     * The 68000 User Stack Pointer (USP) will be set here.
     */
    _user_stack_top = ORIGIN(user_ram) + LENGTH(user_ram);
}
