#include <cs50.h>
#include <stdio.h>

int fact(int n);
int main(void)
{
    //get user input for factorial
    int x = get_int("Find factorial of \n");

    //recursion function
    int y = fact(x);

    //print answer
    printf("Factorial of %i is %i\n", x, y);
}

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}