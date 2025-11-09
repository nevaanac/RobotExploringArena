# Format
This project simulates a **robot exploring an enclosed circular arena** using a **Depth-First Search (DFS)** algorithm. The robot is in an arena surrounded by black walls, which includes markers (gray circles) and obstacles (dark red squares). The markers and obstacles are placed inside the arena randomly at run-time.

The robot does not know where the markers, obstacles, and walls are; and aims to find them. It explores the grid **cell by cell**, moving with commands: ```moveForward(), turnLeft(), turnRight()```

At each cell, it checks whether: the square is **empty**, contains an **obstacle/wall,** or contains a **marker**. The robot stores this information in its memory. When the robot finds a marker, it **erases it** and continues exploring until the entire arena is mapped. At the end of the exploration, it **returns to its starting position** and **drops the markers** there.

# Files and Descriptions
| File | Description |
|------|--------------|
| main.c  |	Main program — sets up the environment and starts the exploration |
| grid.c / grid.h |	Generates the circular grid and walls |
| obstacle.c / obstacle.h |	Places random obstacles inside the grid |
| marker.c / marker.h |	Creates, erases, and manages markers |
| robot.c / robot.h |	Controls robot movement and exploration logic |
| graphics.c / graphics.h |	Provides visualization functions |

# How to Compile and Run
**Compile** ```gcc graphics.c coursework.c grid.c obstacle.c marker.c robot.c -o coursework```
**Run** ```./coursework | java -jar drawapp-4.5.jar```
