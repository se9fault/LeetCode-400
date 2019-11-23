/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the
matrix in spiral order.

Example 1:
Input:
[[ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[ [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        // (r1, c1) is the upper left point of current layer;
        // (r2, c2) is the lower right point
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        // 1, 2, 3, 4
        // 5, 6, 7, 8
        // 9,10,11,12
        while (r1 <= r2 && c1 <= c2) {        // r1=0, c1=0, r2=2, c2=3
            for (int c = c1; c <= c2; c++)
                ans.push_back(matrix[r1][c]); // 1,2,3,4
            for (int r = r1 + 1; r <= r2; r++)
                ans.push_back(matrix[r][c2]); // 8,12
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--)
                    ans.push_back(matrix[r2][c]); // 11,10
                for (int r = r2; r > r1; r--)
                    ans.push_back(matrix[r][c1]); // 9,5
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};
