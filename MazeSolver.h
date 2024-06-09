#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include <vector>
#include <iostream>
#include "Stack.h"

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class MazeSolver {
private:
    std::vector<std::vector<int>> maze;
    std::vector<Point> path;
    int rows, cols;

    bool isSafe(int x, int y) const;
    bool solveMazeUtil(int startX, int startY, int endX, int endY);

public:
    MazeSolver(const std::vector<std::vector<int>>& maze);
    bool solveMaze(int startX, int startY, int endX, int endY);
    void printPath() const;
};

#endif // MAZESOLVER_H
