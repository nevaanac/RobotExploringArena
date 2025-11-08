#ifndef GRID_H
#define GRID_H

int cellsize;
extern int **grid;
extern int num_rows;
extern int num_cols;

int generateGrid();

#define CELL_EMPTY 0
#define CELL_MARKER  1
#define CELL_OBSTACLE 2
#define CELL_ROBOT 3

#endif


