#include "header.h"
#include <string.h>
#include <stdio.h>

typedef struct s_dict t_dict;

int     fac(int len) {
    int fact = 1;
    for (int i = 1; i <= len; i++) {
        fact = fact * i;
    }
    return fact;
}

void    swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void    heap(t_dict *dict, char *str, int size, int n)
{
    if (size == 1)
    {
        if (dictSearch(dict, str) == -1)
            printf("%s\n", str);
        dictInsert(dict, str, 1);
        return ;
    }
    for (int i = 0; i < size; i++) {
        heap(dict, str, size - 1, n);
        if (size % 2 == 1)
            swap(&str[0],  &str[size - 1]);
        else 
            swap(&str[i],  &str[size - 1]);
    }
}

void	printUniquePermutations(char *str)
{
    int len = strlen(str);
    t_dict *dict = dictInit(fac(len));
    heap(dict, str, len, len);
}