#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check that argc == 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // fopen IN file in read mode
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // create buffer[]
    BYTE buffer[] = malloc(sizeof(uint8_t))

    // initialise counter to 1
    int counter = 1

    // while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // if buffer[0] == Oxff
        // and buffer[1] == Oxd8
        // and buffer[2] == Oxff
        // and (buffer[3] & Ocf0) == Oxe0
        if (buffer[0] == Oxff && buffer[1] == Oxd8 && buffer[2] == Oxff && (buffer[3] & Ocf0) == Oxe0)
        {
        // some condition to deal with if a file is open or not
        }
    }


            // sprintf(filename, "%O3i.jpg", counter)
                // counter++
            // fopen in write mode
            // fwrite to out file
}