#include "./header.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_node* create_node(char c)
{
    struct s_node* node;

    node = malloc(sizeof(struct s_node));
    node->c = c;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct s_node* move_node(struct s_node* root, int moves)
{
    if (moves > 0)
    {
        while (moves--)
            root = root->next;
    } else {
        moves = -moves;
        while (moves--)
            root = root->prev;
    }
    return root;
}

struct s_node*  make_doubly_linked_list()
{
    struct s_node* root;
    struct s_node* temp;
    
    for (int i = 0; CS[i]; i++)
    {
        if (i == 0)
            temp = root = create_node(CS[i]);
        else {
            root->next = create_node(CS[i]);
            root->next->prev = root;
            root = root->next;
        }
    }
    root->next = temp;
    temp->prev = root;
    root = root->next;
    return root;
}

char *precious(int *text, int size)
{
    struct s_node*  root;
    char            *str;
 
    str = malloc(size + 1);
    bzero(str, size);
    root = make_doubly_linked_list();
    for (int i = 0; i < size; i++)
    {
        root = move_node(root, text[i]);
        str[i] = root->c;
    }
    return str;
}