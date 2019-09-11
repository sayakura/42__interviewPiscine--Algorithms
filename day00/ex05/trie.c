
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h>
#include "header.h"

struct trie_node *init_trie(void) 
{ 
    struct trie_node *root = NULL; 
  
    root = (struct trie_node *)malloc(sizeof(struct trie_node)); 
    if (root) 
    { 
        int i; 
        root->end = false; 
        for (i = 0; i < ALPHABET_SIZE; i++) 
            root->children[i] = NULL; 
    } 
    return root; 
} 

void insert_trie(struct trie_node *root, char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 

    struct trie_node *tmp = root; 
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(tolower(key[level])); 
        if (!tmp->children[index]) 
            tmp->children[index] = init_trie(); 
        tmp = tmp->children[index]; 
    } 
    tmp->end = true; 
} 

bool search_trie(struct trie_node *root, char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    struct trie_node *tmp = root; 
  
    for (level = 0; level < length; level++) 
    {
        if (!isalpha(key[level]))
            return false;
        index = CHAR_TO_INDEX(tolower(key[level])); 
        if (!tmp->children[index]) 
            return false; 
        tmp = tmp->children[index]; 
    } 
    return (tmp != NULL && tmp->end); 
} 
  