#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int main(void)
{

//prompt user for string input
//count number of characters, words, and sentences
//Exclude spaces
//Coleman formula to identify grade
//if <1 output "before grade 1"
//if >16 output "Grade 16+"

string text = get_string("Text: ");
printf("%s\n", text);

}

int count_letters(string text)
{

}