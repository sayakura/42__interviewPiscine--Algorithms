#include <string.h>
#include "header.h"
#include <stdio.h>

int     binarySearch(struct s_art **arts, int l, int r, char *target)
{
    if (r >= l)
    {
        int mid = (l + (r - 1)) / 2;
        if (!strcmp(arts[mid]->name, target))
            return mid;
        if (strcmp(arts[mid]->name, target) > 0)
            return binarySearch(arts, l, mid - 1, target);
        return binarySearch(arts, mid + 1, r, target);
    }
    return -1;
}

int     searchPrice(struct s_art **arts, int n, char *name)
{
    int             left = 0;
    unsigned int    right = n;
    int             index;

    index = binarySearch(arts, left, right, name);
    if (index == -1)
        return index;
    else
        return arts[index]->price;
}