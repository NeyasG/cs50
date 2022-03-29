// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // load dictionary
    FILE *file = fopen("dictionaries/large", "r");
    if (file == NULL)
    {
        printf("Could not Open File\n");
        return 1;
    }

    char buffer[LENGTH + 1];
    // Read strings from file one at a time
    while(fscanf(file, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));
        if n == NULL
        {
            printf("Not enough memory\n");
            return 1;
        }
    }
    // insert word from dictionary into memory and initialise next node
    strcpy(n->word, "Hello");
    // n-> = NULL;

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
