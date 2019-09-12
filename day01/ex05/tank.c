#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

typedef struct s_elem selem;
typedef struct s_stack sstack;
typedef struct s_tank stank;

sstack *history = NULL;

struct s_stack *stackInit(void)
{
    sstack *s;
    s = malloc(sizeof(sstack));
    s->elem = NULL;
    s->sum = 0;
    return s;
}
int     pop(struct s_stack *stack)
{
    if (!stack || !stack->elem)
        return -1;
    selem *item = stack->elem;
    stack->elem = item->next;
    stack->sum -= item->energy;
    return item->energy;
}

void    push(struct s_stack *stack, int energy)
{
    if (!stack)
        return ;
    selem *item; 
    item = malloc(sizeof(selem));
    item->energy = energy;
    item->next = stack->elem;
    stack->sum += energy;
    stack->elem = item;
}

struct s_tank *initTank(void) {
    stank *tank;

    printf("tank initialized.\n");
    tank = malloc(sizeof(stank));
    tank->n = 1;
    tank->stacks = malloc(sizeof(sstack *) * 1);
    tank->stacks[0] = stackInit();
    return tank;
}

int    is_empty(struct s_stack *stack)
{
    return stack->elem == NULL;
}

void tankPush(struct s_tank *tank, int energy)
{
    for (int i = 0; i < tank->n; i++)
    {
        if (tank->stacks[i]->sum + energy < 1000) {
            if (!history)
                history = stackInit();
            push(tank->stacks[i], energy);
            push(history, i);
            printf("pushing %d to stack[%d] sum: %d\n", energy, i, tank->stacks[i]->sum);
            goto exit;
        } 
        else if (i + 1 == tank->n) {
            printf("creating new stack[%d]...\n", tank->n);
            sstack **new_stack_list = malloc(sizeof(sstack *) * tank->n + 1);
            memcpy(new_stack_list, tank->stacks, sizeof(sstack *) * tank->n);
            free(tank->stacks);
            tank->stacks = new_stack_list;
            tank->stacks[tank->n] = stackInit();
            tank->n++;
        }
    }
    exit:
        return ;
}

int tankPop(struct s_tank *tank)
{
    int           index, ret;

    index = pop(history);
    if (index == -1)
    {
        printf("it's empty : )\n");
        return -1;
    }
    sstack *s = tank->stacks[index];
    ret = pop(s);
    printf("popped %d from stack[%d], sum: %d\n", ret, index, s->sum);
    if (is_empty(s) && index != 0)
    {
        printf("Stack[%d] is empty, destroying it...\n", index);
        free(s);
        tank->n--;
        sstack **new_stack_list = malloc(sizeof(sstack *) * tank->n);
        memcpy(new_stack_list, tank->stacks, sizeof(sstack *) * tank->n);
        tank->stacks = new_stack_list;
    }
    return (1);
}