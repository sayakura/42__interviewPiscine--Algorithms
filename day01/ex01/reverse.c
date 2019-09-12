
#include "header.h"
#include <stdio.h>
#include <stdbool.h>

void printReverse(struct s_node *lst)
{
    static bool printed = false;    

    if (lst->next)
        printReverse(lst->next);
    if (printed)
        printf(" ");
    printf("%s", lst->word);
    printed = true;
}