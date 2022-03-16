#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
    int x = strlen(text);
}