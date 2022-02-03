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
        for (int j = 1; j <= n; j++)
        {
            printf("%i", i);
        }
            printf("\n");
    }
    printf("\n");
}
