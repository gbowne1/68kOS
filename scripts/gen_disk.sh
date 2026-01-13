#!/bin/bash

# scripts/gen_disk.sh
# Creates a FAT12 formatted floppy image

DISK_NAME="floppy.img"
MOUNT_DIR="./mnt_disk"
KERNEL_BIN="kernel.bin"

echo "Creating 720KB Floppy Image..."

# 1. Create a blank 720KB file (1440 sectors of 512 bytes)
dd if=/dev/zero of=$DISK_NAME bs=512 count=1440

# 2. Format as FAT12 using mkfs.vfat
mkfs.vfat -F 12 -n "M68K_OS" $DISK_NAME

# 3. Use mtools to copy the kernel onto the disk without needing root/sudo
# This is cleaner for CI/CD and development
mcopy -i $DISK_NAME $KERNEL_BIN ::kernel.sys

echo "Disk $DISK_NAME generated successfully."
