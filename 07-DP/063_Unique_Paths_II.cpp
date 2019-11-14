/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid.
Now consider if some obstacles are added to the grids. How many unique paths
would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            obstacleGrid[0][0] = 1;

        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();

        for (int i = 1; i < column; i++) {
            // reuse the obstacleGrid array; once we scanned it, the number in
            // it would be the ways to reach that block
            if (obstacleGrid[0][i - 1] == 1 && obstacleGrid[0][i] == 0) {
                obstacleGrid[0][i] = 1;
            }
            else {
                obstacleGrid[0][i] = 0;
            }
        }
        for (int i = 1; i < row; i++) {
            if (obstacleGrid[i - 1][0] == 1 && obstacleGrid[i][0] == 0) {
                obstacleGrid[i][0] = 1;
            }
            else {
                obstacleGrid[i][0] = 0;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] +
                                         obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[row - 1][column - 1];
    }
};
