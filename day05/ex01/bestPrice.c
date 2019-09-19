#include "header.h"
 #include <stdio.h>

typedef struct s_array t_array;

void find(double *list, int size, double *max, double price)
{
    if (!size)
    {
        if (price > *max)
            *max = price;
    }
    else {
        for (int i = size; i > 0; i--) {
            double local_max = price;
            local_max += list[i];
            find(list, size - i, max, local_max);
        }
    }
}

double bestPrice(int pizzaSize, double *prices)
{
   double price = 0;
   double max = 0;
   find(prices, pizzaSize, &max, price);
    return max;
}