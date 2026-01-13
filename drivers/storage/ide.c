/*
 * drivers/storage/ide.c
 * Hard Drive PIO Driver
 */

#include <stdint.h>

#define IDE_BASE 0xFFF000
#define IDE_REG_DATA     (IDE_BASE + 0x0)
#define IDE_REG_SECTOR   (IDE_BASE + 0x2)
#define IDE_REG_COMMAND  (IDE_BASE + 0x7)

void ide_read_sector(uint32_t lba, uint16_t *buffer) {
    /* * 1. Wait for BSY to clear.
     * 2. Write LBA to registers.
     * 3. Send READ command (0x20).
     * 4. Read 256 words (512 bytes) from Data Register.
     */
}

/* End of file */
