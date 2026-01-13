/*
 * fs/fat12/fat12.c
 * Basic FAT12 Read-Only Implementation for M68K
 */

#include <stdint.h>
#include <drivers/storage.h>

/* FAT12 Directory Entry Structure */
typedef struct {
    uint8_t filename[8];
    uint8_t extension[3];
    uint8_t attributes;
    uint8_t reserved[10];
    uint16_t time;
    uint16_t date;
    uint16_t cluster_low;
    uint32_t filesize;
} __attribute__((packed)) fat_dir_entry_t;

/* BPB (BIOS Parameter Block) offsets */
static uint16_t bytes_per_sector;
static uint8_t sectors_per_cluster;
static uint16_t reserved_sectors;

void fat12_init(void) {
    uint8_t boot_sector[512];
    floppy_read_sector(0, boot_sector);

    /* Map BPB values from the boot sector */
    bytes_per_sector = *(uint16_t *)(boot_sector + 11);
    sectors_per_cluster = boot_sector[13];
    reserved_sectors = *(uint16_t *)(boot_sector + 14);
}

void fat12_find_file(const char *name) {
    /* 1. Calculate Root Directory start (reserved + (fats * sectors_per_fat))
     * 2. Load sectors and iterate through fat_dir_entry_t entries
     * 3. Match filename[8] and extension[3]
     */
}

/* End of file */
