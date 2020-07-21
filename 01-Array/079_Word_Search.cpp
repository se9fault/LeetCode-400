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
        if (board.empty() || board[0].empty())
            return false;
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
private:
    int m, n;
    bool dfs(const vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx])
            return false;
        visited[i][j] = true;
        bool res = dfs(board, word, idx + 1, i - 1, j, visited)
                || dfs(board, word, idx + 1, i + 1, j, visited)
                || dfs(board, word, idx + 1, i, j - 1, visited)
                || dfs(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false; // before return to upper level, need to restore
        return res;
    }
};
