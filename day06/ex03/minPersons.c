#include "header.h"
#include <stdio.h>

int		minPersons(int elements, int minPercentage)
{
    double prob = 1.0;
    double reach = 1.0 - (minPercentage / 100.0);
    int ppl = 1;
    while (prob > reach) {
        prob *= 1.0 - ((double)ppl / elements);
        ppl++;
    }
    return ppl;
}