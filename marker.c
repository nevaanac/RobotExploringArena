#include "graphics.h"
#include "grid.h"
#include "marker.h"
#include <stdio.h>
#include <stdlib.h>

const int num_markers = 1;
Marker markers[1];
int marker_radius=10;

int generateMarker() {
    // random marker location
    int i;
    for (i=0; i<num_markers; i++){ //bazıları üst üste geliyo !!!
        markers[i].gridX = rand() % num_cols;
        markers[i].gridY = rand() % num_rows;

        // convert grid to pixel coordinates
        markers[i].x = markers[i].gridX * cellsize + cellsize / 2;
        markers[i].y = markers[i].gridY * cellsize + cellsize / 2;
        markers[i].visible = 1;

        background();
        setColour(gray); // marker color
        fillOval(markers[i].x - marker_radius, markers[i].y - marker_radius,
            marker_radius * 2, marker_radius * 2); //topleftcorner = (x-radius, y-radius)

        grid[markers[i].gridY][markers[i].gridX] = CELL_MARKER; //update grid

    fprintf(stderr, "Marker placed at grid (%d, %d) → pixels (%d, %d)\n",
                markers[i].gridY, markers[i].gridX,
                markers[i].y, markers[i].x);
    }
    return 0;
}

int eraseMarker(int index) {
    if (index < 0 || index >= num_markers) return -1;  // safety check
    if (!markers[index].visible) return 0;              // already erased

    setColour(white); // same as grid background
    fillRect(
        markers[index].gridX * cellsize, 
        markers[index].gridY * cellsize, 
        cellsize, 
        cellsize
    );
    // redraw grid lines for that cell
    setColour(black);
    drawRect(
        markers[index].gridX * cellsize, 
        markers[index].gridY * cellsize, 
        cellsize, 
        cellsize
    );
    
    grid[markers[index].gridY][markers[index].gridX] = CELL_EMPTY; // update grid
    markers[index].visible = 0; // update marker visibility

    fprintf(stderr, "Marker erased from grid (%d, %d)\n", markers[index].gridY, markers[index].gridX);

    return 0;
}

//atMarker, pickupMarker, dropMarker, markerCount