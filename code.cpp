#include <iostream>
#include <vector>

using namespace std;

#define UNASSIGNED 0
#define N 9

// Function to print the grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in a cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
        if (grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num)
            return false;
    }
    return true;
}

// Function to solve the Sudoku grid using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    //bool isEmpty = true;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(grid, row, col, val))
                    {
                        grid[row][col] = val;
                        
                        if (solveSudoku(grid))
                            return true;
                        else
                            grid[row][col] = UNASSIGNED;
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}

int main() {
    int grid[N][N] = {
        {5, 3, UNASSIGNED, UNASSIGNED, 7, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {6, UNASSIGNED, UNASSIGNED, 1, 9, 5, UNASSIGNED, UNASSIGNED, UNASSIGNED},
        {UNASSIGNED, 9, 8, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED},
        {8, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, 3},
        {4, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, 3, UNASSIGNED, UNASSIGNED, 1},
        {7, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, UNASSIGNED, UNASSIGNED, UNASSIGNED, 6},
        {UNASSIGNED, 6, UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 2, 8, UNASSIGNED},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, 4, 1, 9, UNASSIGNED, UNASSIGNED, 5},
        {UNASSIGNED, UNASSIGNED, UNASSIGNED, UNASSIGNED, 8, UNASSIGNED, UNASSIGNED, 7, 9}
    };

    if (solveSudoku(grid)) {
        printGrid(grid);
    }
    else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
