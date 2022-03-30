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
    int text_hash = hash(word);

    // index into table at hash and compare word to dictionary
    for (node *curr_point = table[text_hash]; curr_point != NULL; curr_point = curr_point->next)
    {
        if (strcasecmp(curr_point->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_value = 0;
    hash_value = (toupper(word[0]) - 'A');
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
    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
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

    // printf("Word count: %i", word_count);
    fclose(file);
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
    for (int i = 0; i <= N ; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
