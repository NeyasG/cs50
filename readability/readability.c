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
int y = count_letters(text);
printf("%i\n", y);

}

// function to count letters in a sentence
int count_letters(string text)
{

    // counting all characters and spaces
    int x = strlen(text);
    return(x);
}