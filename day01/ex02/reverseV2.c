#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

typedef struct s_item sitem;
typedef struct s_stack sstack;

struct s_stack *stackInit(void)
{
    sstack *s;
    s = malloc(sizeof(sstack));
    s->item = NULL;
    return s;
}
void *pop(struct s_stack *stack)
{
    if (!stack || !stack->item)
        return NULL;
    sitem *item = stack->item;
    stack->item = item->next;
    return item->word;
}

void push(struct s_stack *stack, char *word)
{
    if (!stack)
        return ;

    sitem *item; 
    item = malloc(sizeof(sitem));
    item->word = word;
    item->next = stack->item;
    stack->item = item;
}
void printReverseV2(struct s_node *lst)
{
    struct s_node *tmp; 
    char           *word;
    bool            printspace = false;
    sstack *s = stackInit();

    tmp = lst;
    while (tmp)
    {
        push(s, tmp->word);
        tmp = tmp->next;
    }
    while ((word = pop(s)))
    {
        if (printspace)
            printf(" ");
        printf("%s", word);
        printspace = true;
    }
    printf("\n");
}