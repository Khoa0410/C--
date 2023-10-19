/* Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct */

#include <bits/stdc++.h>
using namespace std;

const int N = 9;

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Kiểm tra giá trị 'num' đã có trong hàng hay chưa
    for (int c = 0; c < N; c++) {
        if (grid[row][c] == num) {
            return false;
        }
    }

    // Kiểm tra giá trị 'num' đã có trong cột hay chưa
    for (int r = 0; r < N; r++) {
        if (grid[r][col] == num) {
            return false;
        }
    }

    // Kiểm tra giá trị 'num' đã có trong ô 3x3 hay chưa
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

    // Kiểm tra bảng Sudoku đã điền hết hay chưa
    if (!findEmptyLocation(grid, row, col)) {
        return 1;
    }

    int count = 0;
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Bước đệ quy cho chỗ trống tiếp theo
            count += countSudokuSolutions(grid);

            grid[row][col] = 0; // Quay lui và thử giá trị tiếp theo của num
        }
    }

    return count;
}

int main() {
    //freopen(".inp", "r", stdin);

    vector<vector<int>> grid(N, vector<int>(N));

    // Nhập input
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
    }

    int solutionCount = countSudokuSolutions(grid);
    cout << solutionCount << endl;

    return 0;
}