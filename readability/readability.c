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
printf("%i\n", count_letters(text));

}

// function to count letters in a sentence
int count_letters(string text)
{
    int letters = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalnum(text[i]) != false)
        letters ++;
    }
    return(letters++);

    // counting all characters and spaces
    //int x = strlen(text);
    //return(x);
}