/*
 * include/kernel/mm.h
 */

#ifndef MM_H
#define MM_H

#include <stddef.h>

void mm_init(void);
void *kmalloc(size_t size);
void kfree(void *ptr);

#endif

/* End of file */
