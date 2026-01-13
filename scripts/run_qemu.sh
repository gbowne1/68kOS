#!/bin/bash

# Ensure directories exist
mkdir -p boot kernel

# Build the project
make clean
make

# Run QEMU
# -M q800: Macintosh Quadra 800 (68k architecture)
# -bios kernel.bin: Loads our binary at the start of memory
# -nographic: No GUI needed for this level of dev
# -m 16M: Give it 16MB of RAM
qemu-system-m68k \
    -M q800 \
    -bios kernel.bin \
    -m 16M \
    -nographic \
    -serial mon:stdio
