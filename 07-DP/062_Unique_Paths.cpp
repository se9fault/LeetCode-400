/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:
Input: m = 7, n = 3
Output: 28
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[0][0] = 1;

        for (int i = 1; i < n; i++)
            if (grid[0][i - 1] == 1 && grid[0][i] == 0)
                grid[0][i] = 1;
            else
                grid[0][i] = 0;

        for (int i = 1; i < m; i++)
            if (grid[i - 1][0] == 1 && grid[i][0] == 0)
                grid[i][0] = 1;
            else
                grid[i][0] = 0;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                grid[i][j] = (grid[i][j] == 0) ? grid[i - 1][j] + grid[i][j - 1] : 0;

        return grid[m - 1][n - 1];
    }
};
