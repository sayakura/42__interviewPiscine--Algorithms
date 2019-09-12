#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int isEmpty(struct s_queue *queue);

struct s_queue *queueInit(void)
{
    queue *q;

    q = malloc(sizeof(queue));
    q->first = NULL;
    q->last = NULL;
    return q;
}

char *dequeue(struct s_queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    node *head = queue->first;
    if (head == queue->last)
    {
        queue->last = NULL;
        queue->first = NULL;
    }
    else
        queue->first = head->next;
    return head->message;
}

void enqueue(struct s_queue *queue, char *message)
{
    node *new = malloc(sizeof(node));
    new->message = message;
    new->next = NULL;
    new->next = queue->first;
    if (!queue->first)
        queue->first = new;
    if (queue->last)
        queue->last->next = new;
    queue->last = new;
}

char *peek(struct s_queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    return queue->first->message;
}

int isEmpty(struct s_queue *queue)
{
    return (queue->first == NULL);
}