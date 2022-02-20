#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User inputs CC number
    int n = get_long("Credit Card Number\n");

    // Initialise power counter
    int i = 0;
    int sum = 0;

    do
    {
        printf("i = %i\n", i);
         int x = ( (n/(10^i) % 10));
         i ++;
         printf("%i\n", x);
    }
    while( (n/(10^i)) > 1 );
}