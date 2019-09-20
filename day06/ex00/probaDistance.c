#include "header.h"
#include <stdio.h>

double probaDistance(int dist, int *locations, int n)
{
    if (!n)
        return 0.0;
    int slow = 0, fast = 0, cnt = 0;
    while (fast < n){
        if (locations[fast] <= (locations[slow] + dist))
            fast++;
        else {
            cnt += n - fast;
            slow++;
        }
    }
    return  ((double)cnt / (n * (n - 1) / 2));
}