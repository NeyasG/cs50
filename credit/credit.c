#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // User inputs CC number
    int n = get_long("Credit Card Number\n");

    // Initialise power counter
    int i = 0;
    int sum = 0;
    int x = 0;

    do
    {
        // finding individual digit
        x = ( (n/pow(10, i)));
        x = x % 10;

        if ( i % 2 == 0)
        {
            sum = sum + x;
        }
        else
        {
            sum = sum + (x*2);
        }
        printf("sum = %i\n", sum);

        i ++;
    }
    while( x != 0 );
}