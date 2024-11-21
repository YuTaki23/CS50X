// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;
unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// 不区分大小写
bool check(const char *word)
{
    // TODO
    unsigned int hash_index = hash(word);

    node *temp = table[hash_index];
    for (; temp != NULL; temp = temp->next) {
        if (strcasecmp(word, temp->word)) {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += toupper(word[i]);
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    if (source == NULL) {
        printf("The file is failed to open.\n");
        return false;
    }
    // Create space for a new hash table node
    node *buffer = malloc(sizeof(node));

    // 不断添加word到buffer中，直到没有word
    while ((fscanf(source, "%s", buffer->word)) != '\0') {
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL) {
            printf("Wrong.");
            return false;
        }
        // Copy the word into the new node
        strcpy(new_word->word, buffer->word);

        // Hash the word to obtain its hash value
        int hash_index = hash(new_word->word);
        count++;

        // Insert the new node into the hash table (using the index specified by its hash value)
        new_word->next = table[hash_index];
        table[hash_index] = new_word;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // 创建一个新的副本，其中包含load中的所有地址，将这个副本指向这些地址，并free
    node *temp = NULL;
    node *current = NULL;

    for (int i = 0; i < N; i++) {
        current = table[i];
        for (; current != NULL; current = current->next) {
            temp = current;
            free(temp);
        }
    }
    return true;
}
