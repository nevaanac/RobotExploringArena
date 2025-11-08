#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateObstacle(int x, int y) //coordinates of the left corner
{
    fillRect(x, y, 30, 30); //(x, y, width, height)
    return 0;
}

typedef struct{
        int x;
        int y;
} Obstacle;

const int num_obstacles = 20;
Obstacle obstacles[num_obstacles];

int randObstacle(){
    srand(time(NULL)); // random number generator

    int i;
    for (i=0; i<num_obstacles; i++){ //bazıları üst üste geliyo !!!
        obstacles[i].x = (rand() % 10) * 30;  // 0–10 * 30 = 0–300
        obstacles[i].y= (rand() % 10) * 30;
        
        generateObstacle(obstacles[i].x, obstacles[i].y);
        printf("Obstacle %d → x = %d, y = %d\n", i, obstacles[i].x, obstacles[i].y);
    }
    return 0;
}

int isObstacle(int x, int y){
    int i;
    for (i=0; i<num_obstacles; i++){
        if (obstacles[i].x==x && obstacles[i].y==y){
            return 1;
        }
    }
    return 0;
}