

#!/bin/bash
# RollNo: MT26212
# Name: Nishtha Jaiswal

# Compile the assembly system calls
nasm -f elf64 syscall.S -o syscall.o

# Compile the supplied I/O class
g++ -c -nostdlib -fno-exceptions basicIO.cpp -o basicIO.o

# Compile your main program
g++ -c -nostdlib -fno-exceptions MT26212_main.cpp -o MT26212_main.o

# Link everything together into the final executable
ld syscall.o basicIO.o MT26212_main.o -o myprogram