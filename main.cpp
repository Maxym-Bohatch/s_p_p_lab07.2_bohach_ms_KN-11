#include <iostream>
#include "MazeSolver.h"

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    MazeSolver solver(maze);

    int startX = 0, startY = 0;
    int endX = 4, endY = 4;

    if (solver.solveMaze(startX, startY, endX, endY)) {
        std::cout << "Path found:\n";
        solver.printPath();
    }
    else {
        std::cout << "No path found.\n";
    }

    return 0;
}
