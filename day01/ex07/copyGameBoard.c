#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

typedef struct s_node Node;


/*

struct s_node {
	int value;
	struct s_node *random;
	struct s_node *next;
};

 */
Node* cloneGameBoard(Node* node) {

    if (!node)
        return 0;

    Node* old = node;
    Node* temp;

    while (old) {
        temp = old->next;
        old->next = malloc(sizeof(Node));
        old->next->value = old->value;
        old->next->random = 0;
        old->next->next = temp;
        old = temp;
    }
    old = node;
    while (old) {
        if (old->random)
            old->next->random = old->random->next;
        if (old->next)
            old = old->next->next;
        else
            break;
    }
    old = node;
    Node* copy = node->next;
    Node* head = copy;
    while (old && copy) {
        if (old->next)
            old->next = old->next->next;
        if (copy->next)
            copy->next = copy->next->next;
        old = old->next;
        copy = copy->next;
    }
    return head;
}