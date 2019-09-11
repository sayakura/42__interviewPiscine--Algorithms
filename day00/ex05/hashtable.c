#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include "header.h"

// http://www.cse.yorku.ca/~oz/hash.html

/*
djb2
this algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c.
another version of this algorithm (now favored by bernstein) uses
xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33 
(why it works better than many other constants, prime or not)
 has never been adequately explained. 
 */
size_t hash(char *input)
{
    size_t hash = 5381;
    int c;

    while ((c = *input))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        input++;
    }
    return hash;
} //return hash result

struct s_dict *dictInit(int capacity)
{
    struct s_dict * dict;
    struct s_item **items;

    //printf("dict init... cap: %d\n", capacity);
    dict = malloc(sizeof(struct s_dict));
    memset(dict, 0, sizeof(struct s_dict));
    items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
    dict->items = items;
    dict->capacity = capacity;
    return dict;
} //initialize the dictionnary, given as parameter the capacity of the array.

int	dictInsert(struct s_dict *dict, char *key, int value)
{
    int index = hash(key) % dict->capacity;
    struct s_item *head = dict->items[index];
    int ret;

    //printf("inserting a value into dict, the key is [%s], index is %d\n", key, index);
    /* 
    if the associated value is not found from the dictionary
    allocate a new node and insert it to the hashmap 
    if not, update the existing record
    */
    if ((ret = dictSearch(dict, key)) == -1) 
    {
        struct s_item *node;

        if (!(node = malloc(sizeof(struct s_item)))) // allocated the node
            return 0;
        node->key = strdup(key); // dupliacte the key and save it to the node
        node->value = value;
        node->next = NULL;

        if (!head) // if there's none in the linked-list 
            dict->items[index] = node;
        else {
            while (head->next) // find the last node
                head = head->next;
            head->next = node; // append the new node to the end
        }
    } else {
         while (head)
        {
            if (!strcmp(head->key, key))
            {
                head->value = value;
                break ;
            } 
            head = head->next;
        }
    }
    return (1);
} //add one element in the dictionnary, if FAIL return 0, otherwise 1

int     dictSearch(struct s_dict *dict, char *key)
{
    int index = hash(key) % dict->capacity;
    struct s_item *head = dict->items[index];
    
    if (!head)
        return -1;
    while (head)
    {
        if (!strcmp(head->key, key))
            return head->value;
        head = head->next;
    }
    return -1;
} //find one element in the dictionnary, if not found, return -1
