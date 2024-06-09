#include "MazeSolver.h"

MazeSolver::MazeSolver(const std::vector<std::vector<int>>& maze)
    : maze(maze), rows(maze.size()), cols(maze[0].size()) {}

bool MazeSolver::isSafe(int x, int y) const {
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}

bool MazeSolver::solveMazeUtil(int startX, int startY, int endX, int endY) {
    Stack<Point> stack;
    stack.push(Point(startX, startY));

    while (!stack.isEmpty()) {
        Point p = stack.top();
        stack.pop();
        path.push_back(p);

        if (p.x == endX && p.y == endY) {
            return true;
        }

        maze[p.x][p.y] = 2; // Mark as part of path

        // Check all 4 possible movements (right, down, left, up)
        int moveX[] = { 0, 1, 0, -1 };
        int moveY[] = { 1, 0, -1, 0 };

        for (int i = 0; i < 4; ++i) {
            int newX = p.x + moveX[i];
            int newY = p.y + moveY[i];

            if (isSafe(newX, newY)) {
                stack.push(Point(newX, newY));
            }
        }
    }

    return false;
}

bool MazeSolver::solveMaze(int startX, int startY, int endX, int endY) {
    return solveMazeUtil(startX, startY, endX, endY);
}

void MazeSolver::printPath() const {
    for (const auto& p : path) {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }
}
