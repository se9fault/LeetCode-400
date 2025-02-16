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
        // (i1, j1) is the upper left point of current layer;
        // (i2, j2) is the lower right point
        int i1 = 0, j1 = 0, i2 = matrix.size() - 1, j2 = matrix[0].size() - 1;
        // 1, 2, 3, 4
        // 5, 6, 7, 8
        // 9,10,11,12
        while (i1 <= i2 && j1 <= j2) {        // i1=0, j1=0, i2=2, j2=3

            // print the two corners to ensure single rows/columns are fully
            // printed
            for (int j = j1; j <= j2; j++) {
                ans.push_back(matrix[i1][j]); // 1,2,3,4
            }
            for (int i = i1 + 1; i <= i2; i++) {
                ans.push_back(matrix[i][j2]); // 8,12
            }

            // only one row/column, no need to go back
            if (i1 < i2 && j1 < j2) {
                for (int j = j2 - 1; j > j1; j--) {
                    ans.push_back(matrix[i2][j]); // 11,10
                }
                for (int i = i2; i > i1; i--) {
                    ans.push_back(matrix[i][j1]); // 9,5
                }
            }

            ++i1;
            ++j1;
            --i2;
            --j2;
        }
        return ans;
    }
};
