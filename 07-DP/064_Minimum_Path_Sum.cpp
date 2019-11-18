/*
Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    sum[i][j] = grid[0][0];
                if (i == 0)
                    sum[i][j] = sum[i][j-1] + grid[i][j];
                else if (j == 0)
                    sum[i][j] = sum[i-1][j] + grid[i][j];
                else
                    sum[i][j] = std::min(sum[i][j-1], sum[i-1][j]) + grid[i][j];
            }

        return sum[m-1][n-1];
    }
};
