#!/bin/bash

cd ./source

gcc -o calendar main.c

# Check if compilation was successful
if [ $? -eq 0 ]; then
    cp calendar ~/.local/bin #You can replace the bin directory for one that belongs to $PATH, case this doesn't
    cd ~/.local/bin
    chmod +x calendar

    echo "Type calendar into your terminal, should work..."

else
    echo "Compilation failed. Please fix any errors before running the program."
fi
