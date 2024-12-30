## UID: 506129117

## Pipe Up

This program imitates the command line "pipe" operator  by feeding the outputs
of each inputless command into the subsequent one.

## Building

Run 'make' to build the program

## Running

Execute the command './pipe arg1 arg2' where each arg is a valid command
that takes no other input within the command line. This is the
equivalent of running "arg1 | arg2"

Ex Command: ./pipe ls wc wc
Output:       1       3      24
The original ls command outputs 9 lines, 9 words, and 82 bytes(ls | wc).
Running an additional wc on these numbers gives us the 1 output line,
the 3 words(numbers in this case), and the 24 bytes(characters).
This is expected, and adding addition wc's  will not change the output.

## Cleaning up

Running 'make clean' will remove the executable built using make.