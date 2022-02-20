#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // User inputs CC number
    long n = get_long("Credit Card Number\n");
    // printf ( "%ld\n", n);

    // Initialise power counter
    int i = 0;
    int sum = 0;
    long x = 0;
    int length[16];

    do
    {
        // finding individual digit
        x = ( (n/pow(10, i)));
        int y = x % 10;
        length[i] = y;

        if ( i % 2 == 0)
        {
            sum = sum + y; //adding normal digits
        }
        else // adding the sum of the remaining digits
        {
            int z = y*2;
            int a = ( (z/pow(10, 0)));
            int b = ( (z/pow(10, 1)));
            sum = sum + a%10 + b%10;
        }
        // printf("sum = %i\n", sum);

        i ++;
    }
    while( x != 0 );

    // Checksum mod 10 value
    if ((sum % 10 == 0) && i < 15)
    {
        if (length[i-2] == 4)
        {
            printf("VISA\n");
        }
        else if (length[i-2] == 3 && (length[i-3] == 4 || length[i-3] == 7))
        {
            printf("AMEX\n");
        }
        else if (length[i-2] == 5 && (length[i-3] == 1 || length[i-3] == 2 || length[i-3] == 3 || length[i-3] == 4 || length[i-3] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }