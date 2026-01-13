/*
 * include/drivers/storage.h
 */

#ifndef STORAGE_H
#define STORAGE_H

#include <stdint.h>

/* Floppy Functions */
void floppy_init(void);
void floppy_read_sector(uint32_t lba, void *buffer);

/* IDE Functions */
void ide_init(void);
void ide_read_sector(uint32_t lba, uint16_t *buffer);

#endif

/* End of file */
