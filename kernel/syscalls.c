/*
 * kernel/syscalls.c
 * System call dispatch logic
 */

#include <stdint.h>

/*
 * This function will be called by an assembly wrapper 
 * that saves registers before entering C.
 */
void syscall_handler(uint32_t syscall_num) {
    switch (syscall_num) {
        case 1: /* exit */
            break;
        case 2: /* write */
            break;
        default:
            break;
    }
}

/* End of file */
