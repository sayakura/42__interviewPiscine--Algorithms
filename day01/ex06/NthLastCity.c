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

char *NthLastCity(struct s_city *city, int n)
{
    static sstack *l = NULL;
    static sstack *r = NULL;

    char    *item;
    char    *temp;

    if (!l)
    {
        l = stackInit();
        r = stackInit();
        // only once
        printf("---> once\n");
        while (city)
        {
            push(l, city->name);
            city = city->next;
        }
    }
    while (n-- >= 0)
    {
        item = pop(l);
        push(r, item);
    }
    while ((temp = pop(r)))
        push(l, temp);
    return item;
}
