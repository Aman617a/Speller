// // Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

int num_nodes = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowercase_word[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[strlen(word)] = '\0'; // Null-terminate the lowercase word

    int hv = hash(lowercase_word);

    node *n = table[hv];

    while (n != NULL)
    {
        if (strcasecmp(n->word, lowercase_word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

uint32_t hash(const char *key)
{
    uint32_t hash = 0;
    while (*key)
    {
        hash = (hash * 31) +
               tolower(*key); // Convert character to lowercase before hashing
        key++;
    }
    return hash % N; // Limit hash value to the range [0, N - 1]
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("could not open the file\n");
        return false;
    }

    const unsigned MAX_LENGTH = 47;
    char buffer[MAX_LENGTH];

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    while (fgets(buffer, MAX_LENGTH, file))
    {
        // Convert buffer to lowercase
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            buffer[i] = tolower(buffer[i]);
        }
        buffer[strlen(buffer) - 1] = '\0'; // Remove newline character

        uint32_t hv = hash(buffer);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            printf("Could not allocate memory for node\n");
            return false;
        }

        num_nodes++;

        strcpy(n->word, buffer);
        n->next = table[hv];
        table[hv] = n;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num_nodes;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *first = table[i];

        while (first != NULL)
        {
            node *second = first->next;
            free(first);
            first = second;
        }
    }
    return true;
}
