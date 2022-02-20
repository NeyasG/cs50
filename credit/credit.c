#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // User inputs CC number
    int n = get_long("Credit Card Number\n");
    printf("n = %i\n", n); //remove after debug

    // Initialise power counter
    int i = 0;
    double sum = 0;
    int x = 0;

    do
    {
        // finding individual digit
        x = ( (n/pow(10, i)));
        x = x % 10;

        if ( x % i = 0)
        {
            
        }

        i ++;
    }
    while( x != 0 );
}