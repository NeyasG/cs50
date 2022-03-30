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

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word
    text_hash = hash(word);
    // index into table at hash and compare word to dictionary
    curr_point = table[text_hash];
    for (i = 0; i < LENGTH; i++)
    {
        if ((strcasecmp(word, table[text_hash]) == 0)
        {
            return true
        }
        else
        {
            curr_point = curr_point->next;
        }
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_value = 0;
    hash_value = (toupper(word[0]) -'A');
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // load dictionary
    FILE *file = fopen(dictionary, "r");
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
        else // write node ref to first node
        {
            n->next = table[hash_n];
        }

        // Add Hashed node to hash table
        table[hash_n] = n;
        word_count++;
    }

    printf("Word count: %i", word_count);
    free(buffer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
