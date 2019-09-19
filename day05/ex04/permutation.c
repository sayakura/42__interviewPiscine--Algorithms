#include "header.h"
#include <string.h>
#include <stdio.h>

void    swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void    heap(char *str, int size, int n)
{
    if (size == 1)
    {
        printf("%s\n", str);
        return ;
    }
    for (int i = 0; i < size; i++) {
        heap(str, size - 1, n);
        if (size % 2 == 1)
            swap(&str[0],  &str[size - 1]);
        else 
            swap(&str[i],  &str[size - 1]);
    }
}

void	printPermutations(char *str)
{
    int len = strlen(str);
    heap(str, len, len);
}