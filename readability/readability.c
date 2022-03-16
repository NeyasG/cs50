#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int main(void)
{


//count number of characters, words, and sentences
//Exclude spaces
//Coleman formula to identify grade
//if <1 output "before grade 1"
//if >16 output "Grade 16+"

//prompt user for string input
string text = get_string("Text: ");
int x = count_letters(text);
printf("%i\n", x);

}

// function to count letters in a sentence
int count_letters(string text)
{
    int letters = 0;
    for (int y = 0, y > strlen(text), y++)
    {
        if(isalnum(text[y] = true))
        {
            letters++;
        }
    }
    return(letters)
    // counting all characters and spaces
    //int x = strlen(text);
    //return(x);
}