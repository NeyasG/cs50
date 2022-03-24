#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    BYTE buffer[512];
    FILE *c_image = NULL;

    // initialise counter to 1
    int counter = 0;
    char filename[8];

    // while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    while (fread(&buffer, 1, 512, infile) == 512)
    {
        // if buffer[0] == Oxff
        // and buffer[1] == Oxd8
        // and buffer[2] == Oxff
        // and (buffer[3] & Ocf0) == Oxe0
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (counter !=0)
            {
                fclose(c_image);
            }

            sprintf(filename, "%03i.jpg", counter);
            c_image = fopen(filename, "w");
            counter++;
        }

        // fwrite to out file
        if (counter != 0)
        {
            fwrite(&buffer, 512, 1, c_image);
        }
    }
    fclose(c_image);
    fclose(infile);
    return 0;
}