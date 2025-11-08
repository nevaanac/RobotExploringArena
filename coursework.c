#include "grid.c"
#include "obstacle.c"
#include "marker.c"
#include "robot.c"
#include <time.h>

int main(void)
{
    int cellsize=30;
    generateGrid(cellsize);
    //randObstacle(0, 0);
    generateMarker();
    //delay(2000); // wait 2 seconds
    //eraseMarker();
    placeRobot(2, 3);

    return 0;
}

/*commands:
gcc graphics.c coursework.c
./a.out | java -jar drawapp-4.5.jar
*/
