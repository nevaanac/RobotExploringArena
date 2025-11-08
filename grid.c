#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateGrid(void)
{
    //int cellwidth=30; int cellheight=30;
    int cellnums=10;
    int cellsize = 30;
    int gridsize = cellsize * cellnums; // 300

    setColour(red);
    drawRect(0, 0, gridsize, gridsize); // border around the arena --> adjust thickness!!
    setColour(black);

    // Vertical lines
    for (int i = cellsize; i < gridsize; i += cellsize) {
        drawLine(i, 0, i, gridsize);
    }

    // Horizontal lines
    for (int j = cellsize; j < gridsize; j += cellsize) {
        drawLine(0, j, gridsize, j);
    }
    return 0;
}