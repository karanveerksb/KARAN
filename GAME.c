#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

char maze[ROWS][COLS] = {
    {'S', '.', '#', '.', 'E'},
    {'.', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.'},
    {'.', '.', '.', '#', '.'},
    {'#', '#', '.', '.', '.'}
};

bool solveMazeDFS(int x, int y) {
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS || maze[x][y] == '#' || maze[x][y] == '*') {
        return false;
    }
    if (maze[x][y] == 'E') {
        return true;
    }
    
    maze[x][y] = '*'; // Mark as part of the solution path

    // Explore neighbors
    if (solveMazeDFS(x - 1, y) || solveMazeDFS(x + 1, y) ||
        solveMazeDFS(x, y - 1) || solveMazeDFS(x, y + 1)) {
        return true;
    }

    maze[x][y] = '.'; // Unmark if not part of the solution path
    return false;
}
int i,j;
void displayMaze() {
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Original Maze:\n");
    displayMaze();
    
    if (solveMazeDFS(0, 0)) {
        printf("Maze Solved:\n");
        displayMaze();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
