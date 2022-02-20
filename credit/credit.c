#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User inputs CC number
    int n = get_long("Credit Card Number\n");
    printf("n = %i\n", n); //remove after debug

    // Initialise power counter
    int i = 0;
    int sum = 0;

    do
    {
        printf("i = %i\n", i); //remove after debug
         int x = ( (n/(10^1)));
         i ++;
         printf("%i\n", x); //remove after debug
    }
    while( (n/(10^i)) > 0 );
}