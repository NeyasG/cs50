#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Pyramid Height: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        printf("#");
    }
    printf("\n");
}
