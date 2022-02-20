#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User inputs CC number
    n = get_long("Credit Card Number");

    // Initialise power counter
    int i = 0;
    int sum = 0;
    do
    {
         int x = ( (n/(10^i) % 10));
         printf(x);
    }
    while( (n/(10^i)) > 0 );
}