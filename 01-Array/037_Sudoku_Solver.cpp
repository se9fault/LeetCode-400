/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:
    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of
    the 9 3x3 sub-boxes of the grid.
    Empty cells are indicated by the character '.'.

Note:
The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }

private:
    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;
        if (j >= 9)
            return helper(board, i + 1, 0);
        if (board[i][j] != '.')
            return helper(board, i, j + 1);
        for (char c = '1'; c <= '9'; ++c) {
            if (!isValid(board, i , j, c))
                continue;
            board[i][j] = c;
            if (helper(board, i, j + 1))
                return true;
            board[i][j] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        for (int x = 0; x < 9; ++x) {
            if (board[x][j] == val)
                return false;
        }
        for (int y = 0; y < 9; ++y) {
            if (board[i][y] == val)
                return false;
        }
        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[x + row][y + col] == val)
                    return false;
            }
        }
        return true;
    }
};
