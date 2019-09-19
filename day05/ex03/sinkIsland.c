#include "header.h"

void sinkIsland(int **map, int row, int col)
{
    if (map[col][row])
        map[col][row] = 0;
    if (map[col + 1][row])
        sinkIsland(map, row, col + 1);
    if (map[col][row + 1])
        sinkIsland(map, row + 1, col);
    if (row - 1 >= 0 && map[col][row - 1])
        sinkIsland(map, row - 1, col);
    if (col - 1 >= 0 && map[col - 1][row])
        sinkIsland(map, row, col- 1);
}


