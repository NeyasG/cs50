#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    // Get user input for Pyramid Height
    do
    {
        n = get_int("Pyramid Height: ");
    }
    while (n < 1 || n > 8);

    //initial for loop
    for (int i = 1; i <= n; i++)
    {
        //Print intial spaces
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        //Print left side Hashes
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        //Print middle spaces
        printf("  ");

        //Print right side hashes
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
