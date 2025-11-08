#include "grid.c"
#include "obstacle.c"
#include "marker.c"
#include <time.h>

int drawRobot(int centerX, int centerY) //draws robot to the center
{
    int x_triangle[3];
    int y_triangle[3];
    int size=10;
    
    x_triangle[0] = centerX;           // top vertex
    y_triangle[0] = centerY - size;

    x_triangle[1] = centerX - size;    // bottom-left
    y_triangle[1] = centerY + size;

    x_triangle[2] = centerX + size;    // bottom-right
    y_triangle[2] = centerY + size;

    setColour(blue);
    drawPolygon(3, x_triangle, y_triangle);
    return 0;
}

int placeRobot(int x, int y){ //places robot to the given CELLS (x, y)
    int cellsize=30; //ADJUST !!!
    int robotX = x * cellsize + cellsize / 2; //centers the robot
    int robotY = y * cellsize + cellsize / 2;
    drawRobot(robotX, robotY);
    return 0;
}