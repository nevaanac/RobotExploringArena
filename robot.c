#include "graphics.h"
#include "robot.h"
#include "marker.h"
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

int size=10;
Robot robot;

int drawRobot(int centerX, int centerY)
{
    foreground();
    robot.centerX = centerX;
    robot.centerY = centerY;

    // depending on direction, draw triangle facing that way
    int x = centerX;
    int y = centerY;

    if (robot.direction == 0) { // up
        robot.x_triangle[0] = x;
        robot.y_triangle[0] = y - size;
        robot.x_triangle[1] = x - size;
        robot.y_triangle[1] = y + size;
        robot.x_triangle[2] = x + size;
        robot.y_triangle[2] = y + size;
    }
    else if (robot.direction == 1) { // right
        robot.x_triangle[0] = x + size;
        robot.y_triangle[0] = y;
        robot.x_triangle[1] = x - size;
        robot.y_triangle[1] = y - size;
        robot.x_triangle[2] = x - size;
        robot.y_triangle[2] = y + size;
    }
    else if (robot.direction == 2) { // down
        robot.x_triangle[0] = x;
        robot.y_triangle[0] = y + size;
        robot.x_triangle[1] = x - size;
        robot.y_triangle[1] = y - size;
        robot.x_triangle[2] = x + size;
        robot.y_triangle[2] = y - size;
    }
    else if (robot.direction == 3) { // left
        robot.x_triangle[0] = x - size;
        robot.y_triangle[0] = y;
        robot.x_triangle[1] = x + size;
        robot.y_triangle[1] = y - size;
        robot.x_triangle[2] = x + size;
        robot.y_triangle[2] = y + size;
    }
    setColour(blue);
    fillPolygon(3, robot.x_triangle, robot.y_triangle);
    return 0;
}

int placeRobot(int x, int y){ //places robot to the given CELLS (x, y) --> USELESS ??
    int cellsize=30; //ADJUST !!!
    int centerX = x * cellsize + cellsize / 2; //centers the robot
    int centerY = y * cellsize + cellsize / 2;
    robot.direction = 0; // start facing UP
    drawRobot(centerX, centerY);
    return 0;
}

int turnRight() { // (0→1→2→3→0)
    //erase old robot
    setColour(white);
    fillPolygon(3, robot.x_triangle, robot.y_triangle);

    robot.direction = (robot.direction + 1) % 4;
    drawRobot(robot.centerX, robot.centerY);
    return 0;
}

int turnLeft() { // (0→3→2→1→0)
    //erase old robot
    setColour(white);
    fillPolygon(3, robot.x_triangle, robot.y_triangle);

    robot.direction = (robot.direction -1 ) % 4;
    drawRobot(robot.centerX, robot.centerY);
    return 0;
}

int moveForward(){
    int cellsize = 30;
    // erase old robot
    setColour(white);
    fillPolygon(3, robot.x_triangle, robot.y_triangle);

    if (robot.direction == 0)      robot.centerY -= cellsize; // up
    else if (robot.direction == 1) robot.centerX += cellsize; // right
    else if (robot.direction == 2) robot.centerY += cellsize; // down
    else if (robot.direction == 3) robot.centerX -= cellsize; // left

    drawRobot(robot.centerX, robot.centerY);
    return 0;
}

int atMarker(){
    for (int i = 0; i < num_markers; i++) {
        if (markers[i].visible == 1) {
            int x_distance = abs(robot.centerX - markers[i].x);
            int y_distance = abs(robot.centerY - markers[i].y);
            if (x_distance < 5 && y_distance < 5) { // within same cell
                return 1;
            }
        }
    }
    return 0;
}

int pickupMarker() { //erases and picks up marker, then goes to corner
    while (!atMarker()) {
        if (robot.centerX < markers[0].x)
            robot.direction = 1; // right
        else if (robot.centerX > markers[0].x)
            robot.direction = 3; // left
        else if (robot.centerY < markers[0].y)
            robot.direction = 2; // down
        else if (robot.centerY > markers[0].y)
            robot.direction = 0; // up

        moveForward();
        sleep(200);
    }
    printf("Marker found at (%d, %d)!\n", markers[0].x, markers[0].y);
    eraseMarker(0);
    goToCorner();
    return 0;
}

int goToCorner() { //goes to bottom right corner
    int targetX = (num_cols - 1) * cellsize + cellsize / 2;
    int targetY = (num_rows - 1) * cellsize + cellsize / 2;

    while (robot.centerX != targetX || robot.centerY != targetY) {
        if (robot.centerX < targetX)
            robot.direction = 1; // right
        else if (robot.centerX > targetX)
            robot.direction = 3; // left
        else if (robot.centerY < targetY)
            robot.direction = 2; // down
        else if (robot.centerY > targetY)
            robot.direction = 0; // up

        moveForward();
        sleep(200);
    }
    dropMarker();
    return 0;
}

int dropMarker() {
    markers[0].gridX = num_cols - 1;
    markers[0].gridY = num_rows - 1;
    markers[0].x = markers[0].gridX * 30 + 15;
    markers[0].y = markers[0].gridY * 30 + 15;
    markers[0].visible = 1;

    background();
    setColour(gray);
    fillOval(markers[0].x - marker_radius, markers[0].y - marker_radius,
             marker_radius * 2, marker_radius * 2);

    grid[markers[0].gridY][markers[0].gridX] = CELL_MARKER;

    printf("Marker dropped at bottom-right corner!\n");
    return 0;
}