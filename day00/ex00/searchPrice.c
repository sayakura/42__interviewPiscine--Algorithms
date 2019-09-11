#include <string.h>
#include "header.h"

int  searchPrice(struct s_art **arts, char *name)
{
    for (int i = 0; arts[i] && arts[i]->name; i++)
        if (!strcmp(name, arts[i]->name))
            return arts[i]->price;
    return -1;
}