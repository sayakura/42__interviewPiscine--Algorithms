#include "header.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_array t_array;

void test(t_array *arr, int size)
{
    if (!size)
        arrayPrint(arr);
    else {
        for (int i = size; i > 0; i--) {
            t_array *tmp = arrayClone(arr);
            arrayAppend(tmp, i);
            test(tmp, size - i);
        }
    }
}

void printPossibleSlices(int pizzaSize)
{
    t_array *arr = arrayInit();
    test(arr, pizzaSize);
}