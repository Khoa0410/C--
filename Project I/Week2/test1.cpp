#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' already exists in the current row
    for (int c = 0; c < N; c++) {
        if (grid[row][c] == num) {
            return false;
        }
    }

    // Check if 'num' already exists in the current column
    for (int r = 0; r < N; r++) {
        if (grid[r][col] == num) {
            return false;
        }
    }

    // Check if 'num' already exists in the current sub-square 3x3
    int subGridStartRow = row - row % 3;
    int subGridStartCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[subGridStartRow + r][subGridStartCol + c] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyLocation(vector<vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

int countSudokuSolutions(vector<vector<int>>& grid) {
    int row, col;

    // Check if the Sudoku table is already filled
    if (!findEmptyLocation(grid, row, col)) {
        return 1; // Found a solution
    }

    int count = 0;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Assign the number

            // Recursively search for the next empty location
            count += countSudokuSolutions(grid);

            grid[row][col] = 0; // Backtrack and try the next number
        }
    }

    return count;
}

int main() {
    //freopen(".inp", "r", stdin);

    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
    }

    /*for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << grid[i][j] << ' ';
        cout << endl;
    }*/

    int solutionCount = countSudokuSolutions(grid);
    cout << solutionCount << endl;

    return 0;
}