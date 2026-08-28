#!/bin/bash
# RollNo: MT26212
# Name: Nishtha Jaiswal

nasm -f elf64 syscall.S -o syscall.o
g++ -c -nostdlib -fno-exceptions MT26212_main.cpp -o MT26212_main.o
ld syscall.o MT26212_main.o -o myprogram