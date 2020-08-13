/*
Given a 2D board containing 'X' and 'O'(the letter O), capture all regions
surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the
border of the board are not flipped to 'X'. Any 'O' that is not on the border
and it is not connected to an 'O' on the border will be flipped to 'X'. Two
cells are connected if they are adjacent cells connected horizontally or
vertically.
*/

// Solution:
// start DFS from borders; Os connected to the border should not be flipped;
// all the other Os need to be flipped.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O')
                        dfs(board, i , j); // mark border 'O' as '$'
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '$')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
private:
    int m, n;
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
};
