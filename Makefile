# Makefile
CC = m68k-elf-gcc
AS = m68k-elf-as
LD = m68k-elf-ld
OBJCOPY = m68k-elf-objcopy

CFLAGS = -std=c99 -m68000 -ffreestanding -O2 -Wall -Wextra -Iinclude
ASFLAGS = -m68000
LDFLAGS = -T linker.ld -nostdlib

OBJ = boot/vectors.o boot/boot.o kernel/main.o

all: kernel.bin

kernel.bin: kernel.elf
	$(OBJCOPY) -O binary kernel.elf kernel.bin

kernel.elf: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o kernel.elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(ASFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(ASFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) kernel.elf kernel.bin
