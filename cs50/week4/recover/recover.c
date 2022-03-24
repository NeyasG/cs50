#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check that argc == 2
        // else printf "correct usage" and return 1
    // check if file can be opened
        // else error message and return 1
    // fopen file
    // fread file looking for jpeg signatures
    // IF 4 bytes = jpeg
        // fopen out file
        // fread to temp array
            // if jpeg signature found stop
            // fwrite to out file with name sprintf(###.jpg [8 bytes])

}