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
    // actually something of a dfs
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

private:
    int m, n;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        if (idx == word.length() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '*'; // used
        bool found = dfs(board, word, i+1, j, idx+1)
                  || dfs(board, word, i, j+1, idx+1)
                  || dfs(board, word, i-1, j, idx+1)
                  || dfs(board, word, i, j-1, idx+1);
        board[i][j] = temp;
        return found;
    }
};
