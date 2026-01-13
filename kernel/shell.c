/*
 * kernel/shell.c
 * Basic command line interface for 68kOS
 */

#include <stdint.h>
#include <string.h>
#include <drivers/char.h>
#include <fs/fat12/fat12.h>

#define MAX_INPUT 64

/* External assembly routine to drop to userland */
extern void jump_to_user(void);

void shell_prompt(void) {
    serial_puts("\n68kOS> ");
}

void shell_run(void) {
    char input[MAX_INPUT];
    int index = 0;

    serial_puts("68kOS Kernel Shell Initialized.\n");
    shell_prompt();

    for (;;) {
        /* This is a placeholder for a 'serial_getc' function */
        char c = serial_getc();

        if (c == '\r' || c == '\n') {
            input[index] = '\0';
            serial_puts("\n");

            if (strcmp(input, "help") == 0) {
                serial_puts("Commands: help, ls, run\n");
            } else if (strcmp(input, "run") == 0) {
                serial_puts("Loading user/hello.bin...\n");
                /* In a real scenario, you'd use fat12_find_file here */
                jump_to_user();
            } else if (index > 0) {
                serial_puts("Unknown command.\n");
            }

            index = 0;
            shell_prompt();
        } else {
            if (index < MAX_INPUT - 1) {
                input[index++] = c;
                serial_putc(c); /* Echo back to user */
            }
        }
    }
}

/* End of file */
