# debug.gdb
# Advanced helper macros for 68kOS debugging

define show_sr
    printf "Status Register: 0x%x\n", $sr
    printf "  Trace: %d  Super: %d  Interrupt Mask: %d\n", \
           ($sr >> 15) & 1, ($sr >> 13) & 1, ($sr >> 8) & 7
end

document show_sr
    Decodes the M68K Status Register (SR) bits.
end

define dump_stack
    printf "Current Stack Pointer (SP): 0x%x\n", $sp
    x/16xw $sp
end

document dump_stack
    Dumps the top 16 words of the current stack.
end

# End of file
