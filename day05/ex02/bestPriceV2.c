
#include "header.h"
#include <stdlib.h>
#include <stdio.h>

double optimizedBestPrice(int pizzaSize, double *prices)
{
    double *mem = malloc(pizzaSize * sizeof(double)), tmp;
    mem[0] = 0;
    for (int i = 1; i <= pizzaSize; i++) {
        double max = 0;
        for (int j = i; j >= i / 2; j--) {
            if (j == i)
                mem[j] = prices[j];
            tmp = mem[j] + mem[i - j];
            if (tmp > max)
                max = tmp;
        }
        mem[i] = max;
    }
    return mem[pizzaSize];
}