#include "grid.c"
#include "obstacle.c"
#include "marker.c"
#include <time.h>

int main(void)
{
    generateGrid();
    //randObstacle(0, 0);

    generateMarker();
    //delay(2000); // wait 2 seconds
    //eraseMarker();

    return 0;
}

/*commands:
gcc graphics.c coursework.c
./a.out | java -jar drawapp-4.5.jar
*/
