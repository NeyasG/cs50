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
         printf("i = %i\n", i); //remove after debug
         x = ( (n/pow(10, i)));
         x = x % 10;
         i ++;
         printf("x = %i\n", x); //remove after debug
    }
    while( x != 0 );
}