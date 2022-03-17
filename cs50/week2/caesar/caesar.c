#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char a, int x);
bool only_digits(string digits);
int main(int argc, string argv[])
{
    printf("argv[1] = %s\n", argv[1]);
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
        //printf("%c \n", plain_text[1]);
        // run cipher function on string array per character
        for (int j = 0; j < strlen(plain_text); j++)
        {
            plain_text[j] = rotate(plain_text[j], key);
        }
        //plain_text[1] = rotate(plain_text[1], 1);
        printf("ciphertext: %s\n", plain_text);
    }
    return 0;
    //char ch = rotate('a', 2);
    //printf("Rotated = %c\n", ch);
    // print cipher
    //printf("ciphertextL: %s\n", cipher_text);
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
    if (isupper(a))
    {
        char c = ((a - 'A') + x) % 26;
        c = c + 'A';
        return c;
    }
    else
        if (islower(a))
    {
        char c = ((a - 'a') + x) % 26;
        c = c + 'a';
        return c;
    }
    else
    {
        return a;
    }
}