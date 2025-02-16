/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:
board =
[ ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E'] ]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(board, word, 0, i, j, m, n, len)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word, int idx,
                   int i, int j, int m, int n, int len) {
        if (i >= m || i < 0 || j >= n || j < 0) {
            return false;
        }
        if (word[idx] != board[i][j]) {
            return false;
        }
        if (idx == len - 1) {
            return true;
        }

        // mark '-' on board as visited
        board[i][j] = '-';
        if (backtrack(board, word, idx + 1, i + 1, j, m, n, len) ||
            backtrack(board, word, idx + 1, i - 1, j, m, n, len) ||
            backtrack(board, word, idx + 1, i, j + 1, m, n, len) ||
            backtrack(board, word, idx + 1, i, j - 1, m, n, len)) {
            return true;
        }
        board[i][j] = word[idx];
        return false;
    }
};
