#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Pyramid Size: ");
    }
    while (n < 1);

    for (int i = 0, i < n; i++)
    {
        printif("#")
    }
    printif("\n");
}
