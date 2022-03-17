#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char a, int x);
bool only_digits(string digits);
int main(int argc, string argv[])
{
    // Get key value from command line argument
    if (argc != 2)
    {
        // prompt user for string input
        printf("Usage: ./caesar key\n");
        return 1;
    }

        // if not decimal digit print error message and return 1
        // if error print error message and return 1
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // convert to int from string
        int key = atoi(argv[1]);
        string plain_text = get_string("plaintext: ");
    }

    char ch = rotate('A', 1);
    printf("Rotated = %c\n", ch);
    // run cipher function on string array per character
    // apply key to find resulting character
    // print cipher
    // return 0
}

bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]) != 0)
        {
            return true;
        }
    }
    return false;
}

char rotate(char a, int x)
{
    if (isalpha(a))
    {
        char c = (a + x) % 26;
        return c;
    }
    else
    {
        return a;
    }
}