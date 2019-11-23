/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example:
Consider the following matrix:
[ [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30] ]
Given target = 5, return true.
Given target = 20, return false.

Solution: start from the bottom left number; if target is bigger, go right; if
target if smaller. go up.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size(), x = m - 1, y = 0;
        while (x >= 0 && y < n) {
            if (target == matrix[x][y])
                return true;
            else if (target > matrix[x][y])
                ++y;
            else
                --x;
        }
        return false;
    }
};
