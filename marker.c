#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int visible; // 1 if marker is drawn, 0 if collected
} Marker;

const int num_markers = 10;
Marker markers[num_markers];
int marker_radius=10;

int generateMarker() {
    int cellsize = 30;
    int grid_size = 10;

    // random marker location
    int i;
    for (i=0; i<num_markers; i++){ //bazıları üst üste geliyo !!!
        markers[i].x = (rand() % grid_size) * cellsize + cellsize / 2;
        markers[i].y = (rand() % grid_size) * cellsize + cellsize / 2;
        markers[i].visible = 1;

        setColour(gray); // marker color
        fillOval(markers[i].x - marker_radius, markers[i].y - marker_radius,
            marker_radius * 2, marker_radius * 2); //topleftcorner = (x-radius, y-radius)

        printf("Marker placed at (%d, %d)\n", markers[i].x, markers[i].y);
    }
    return 0;
}

/*int pickupMarker() { //erases the marker
    if (markers[i].visible == 1) {
        setColour(white); // background color of arena
        fillOval(marker.x - marker_radius, marker.y - marker_radius,
            marker_radius * 2, marker_radius * 2); //topleftcorner = (x-radius, y-radius)
        marker.visible = 0;
        printf("Marker erased.\n");
    }
    return 0;
}*/


//atMarker, pickupMarker, dropMarker, markerCount