#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check that argc == 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // fopen IN file in read mode
        // else error message and return 1
    // create buffer[]
    // initialise counter to 1
    // while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
        // if buffer[0] == Oxff
        // and buffer[1] == Oxd8
        // and buffer[2] == Oxff
        // and (buffer[3] & Ocf0) == Oxe0
            // sprintf(filename, "%O3i.jpg", counter)
                // counter++
            // fopen in write mode
            // fwrite to out file
}