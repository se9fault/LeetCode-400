/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are
all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = m ? grid[0].size() : 0;
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }

private:
    int m, n;
    void eraseIslands(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i, j + 1);
        eraseIslands(grid, i, j - 1);
    }
};
