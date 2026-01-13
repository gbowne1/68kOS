/*
 * include/kernel/syscalls.h
 */

#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

/* Define syscall numbers */
#define SYS_EXIT  1
#define SYS_READ  2
#define SYS_WRITE 3

void syscall_handler(uint32_t syscall_num);

#endif

/* End of file */
