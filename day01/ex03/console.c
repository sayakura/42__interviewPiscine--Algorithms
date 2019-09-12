#include <unistd.h>
#include <string.h>
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
int     pop(struct s_stack *stack)
{
    if (!stack || !stack->item)
        return -1;
    sitem *item = stack->item;
    stack->item = item->next;
    return item->idx;
}

void push(struct s_stack *stack, int idx)
{
    if (!stack)
        return ;

    sitem *item; 
    item = malloc(sizeof(sitem));
    item->idx = idx;
    item->next = stack->item;
    stack->item = item;
}

#define bufsiz 255
char    *readline()
{
    char    *buffer;
    size_t  bufsize = bufsiz;
    size_t  howmany;

    buffer = malloc(sizeof(255));
    howmany = getline(&buffer,&bufsize,stdin);
    buffer[howmany - 1] = '\0';
    return buffer;
}

char *strjoin(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result) 
    {
        strcpy(result, s1);
        strcat(result, s2);
    }
    return result;
}

char *console(void){
    size_t  init_size = 255;
    char    **message_slots;
    char    *message;
    int     index = 0;
    int     tmp;
    sstack  *s;

    message_slots = malloc(sizeof(char *) * init_size);
    s = stackInit();
    while (1)
    {
        printf(":> ");
        message = readline();
        if (!strcmp(message, "UNDO"))
        {
            tmp = pop(s);
            free(message_slots[tmp]);
            message_slots[tmp] = NULL;
            index = !index ? 0 : index - 1;
        }
        else if (!strcmp(message, "SEND"))
            break ;
        else
        {
            message_slots[index] = message;
            push(s, index);
            index++;
        }
        for (int i = 0; i < index; i++)
        {
            if (message_slots[i] != NULL)
            {
                printf("%s", message_slots[i]);
                printf(" ");
            }
        }
        printf("\n");
    }
    free(s);
    free(message);
    message = "";
    for (int i = 0; i < index; i++)
        if (message_slots[i] != NULL)
        {
            message = strjoin(message, message_slots[i]);
            if (i + 1 < index)
                message = strjoin(message, " ");
        }
    return message;
}


