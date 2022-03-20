#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
        float x = 3;
        float y = 5;

        float majority = x / y;
        majority = round(majority);

        printf("%fd\n", majority);

}

