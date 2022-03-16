#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{

//prompt user for string input
    string text = get_string("Text: ");
//printing number of letters
//printf("%i\n", count_letters(text));
    float let = count_letters(text);
//printing number of words
//printf("%i\n", count_words(text));
    float word = count_words(text);
//printing number of sentences
//printf("%i\n", count_sentences(text));
    float sent = count_sentences(text);

//calculate the Coleman-Liau index for text
    float L = let / (word / 100);
    float S = sent / (word / 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int rounded_index = round(index);

//output Grade level
    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
        return (0);
    }
    if (rounded_index > 16)
    {
        printf("Grade 16+\n");
        return (0);
    }
    else
    {
        printf("Grade %i\n", rounded_index);
        return (0);
    }

}

// function to count letters
int count_letters(string text)
{
    int letters = 0;
    //looping through string array
    for (int i = 0; i < strlen(text); i++)
    {
        //checking for alphanumerics
        if (isalnum(text[i]) != false)


            letters ++;
        }

    return (letters++);

}

//function to count numbers
int count_words(string text)
{
    int words = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if (isspace(text[j]) != 0)


            words++;

    }

    words = words + 1;
    return (words);
}

//function to count sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')


            sentences++;
        }
    return(sentences);
}