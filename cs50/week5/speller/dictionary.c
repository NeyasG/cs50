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
    // load dictionary
    FILE *file = fopen("dictionaries/large.txt", "r");
    if (file == NULL)
    {
        return false;
    }

    // Read strings from file one at a time
    char *buffer = malloc(sizeof(LENGTH + 1));
    while(fscanf(file, "%s", buffer) != EOF)
    {
        // Create node and copy string into node->word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, buffer);
        // Use Hash function
        int hash_n = hash(n->word);

        //check if head does not exist
        if (table[hash_n] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = 
        }
        // Add Hashed node to hash table

        free(&n);
    }
    // insert word from dictionary into memory and initialise next node

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
