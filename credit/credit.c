#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // User inputs CC number
    long n = get_long("Credit Card Number\n");
    printf ( "%ld\n", n);

    // Initialise power counter
    int i = 0;
    int sum = 0;
    long x = 0;

    do
    {
        // finding individual digit
        x = ( (n/pow(10, i)));
        int y = x % 10;
        printf("y = %i\n", y);

        if ( i % 2 == 0)
        {
            sum = sum + y;
        }
        else
        {
            int z = y*2;
            sum + ((z/pow(10, 0)) % 10) + ((z/pow(10, 1)) % 10);
        }
        printf("sum = %i\n", sum);

        i ++;
    }
    while( x != 0 );

    // Checksum mod 10 value
    if (sum % 10 == 0)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}