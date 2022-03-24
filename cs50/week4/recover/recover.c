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
    // check if file can be opened
        // else error message and return 1
    // fopen file
    // while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
        // if jpeg signature found
            // fwrite to out file with name sprintf(###.jpg [8 bytes])
}