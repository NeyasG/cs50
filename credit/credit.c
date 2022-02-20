#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // User inputs CC number
    double n = get_long("Credit Card Number\n");
    printf("n = %f\n", n); //remove after debug

    // Initialise power counter
    double i = 0;
    double sum = 0;

    do
    {
        printf("i = %f\n", i); //remove after debug
         int x = ( (n/pow(10,i)));
         x = x % 10;
         i ++;
         printf("x = %i\n", x); //remove after debug
    }
    while( (n/pow(10,i)) > 0 );
}