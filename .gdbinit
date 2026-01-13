# .gdbinit
# Automated GDB startup for 68kOS

# Connect to QEMU's GDB stub (default port 1234)
target remote :1234

# Load the symbol table from the ELF file
file kernel.elf

# Set a breakpoint at the kernel entry point
break kmain

# Set a breakpoint at the userland entry point
break main

# Provide a better view of registers and assembly
layout regs
layout asm

# Ensure we stay in the current mode
set disassembly-flavor motorola

# End of file
