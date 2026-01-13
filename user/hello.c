/*
 * user/hello.c
 * A simple user-mode program for the M68K OS.
 */

#include <stdint.h>

/* Simple syscall wrapper for writing to the console */
void sys_print(const char *msg) {
    __asm__ __volatile__ (
        "move.l %0, %%a0\n"    /* Pass message pointer in A0 */
        "move.l #3, %%d0\n"    /* Syscall #3 is SYS_WRITE */
        "trap #0\n"            /* Trigger the kernel handler */
        :
        : "g"(msg)
        : "d0", "a0"
    );
}

void main(void) {
    sys_print("Hello from Userland!\n");

    /* Infinite loop to prevent falling off the end */
    for(;;);
}

/* End of file */
