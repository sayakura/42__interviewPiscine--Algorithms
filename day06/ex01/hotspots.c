#include "header.h"
#include <stdio.h>

int selectHotspots(struct s_hotspot **hotspots)
{
    int cnt = 0, last_end = 0, overlapped = 0;
    while (hotspots[cnt])
        cnt++;
    if (cnt == 1)
        return 1;
    else if (!cnt)
        return 0;
    for (int i = 1; i < cnt; i++) {
        if (hotspots[i]->pos - (hotspots[i]->radius) < last_end)
            overlapped++;
        else 
            last_end = hotspots[i]->pos + (hotspots[i]->radius);
    }
    return cnt - overlapped;
}