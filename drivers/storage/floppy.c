/*
 * drivers/storage/floppy.c
 * Support for 360k, 400k, 720k, 800k floppies
 */

#include <stdint.h>

typedef struct {
    uint16_t sectors_per_track;
    uint16_t sides;
    uint16_t tracks;
} floppy_geometry_t;

/* Standard MFM geometries */
static const floppy_geometry_t geom_720k = { 9, 2, 80 };
static const floppy_geometry_t geom_800k = { 10, 2, 80 };

void floppy_read_sector(uint32_t lba, void *buffer) {
    /* * Logic to convert LBA to Head/Cylinder/Sector.
     * Then command the FDC via MMIO registers.
     */
}

/* End of file */
