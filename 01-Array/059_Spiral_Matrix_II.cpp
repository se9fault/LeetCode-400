/*
Given a positive integer n, generate a square matrix filled with elements from 1
to n2 in spiral order.

Example:
Input: 3
Output:
[[ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int left, right, top, down, index;
        left = top = index = 0, right = down = n-1;
        // 1,2,3
        // 8,9,4
        // 7,6,5
        while (left <= right && top <= down) {
            for (int j = left; j <= right; j++)
                res[top][j] = ++index;   // 1,2,3
            top++;
            for (int i = top; i <= down; i++)
                res[i][right] = ++index; // 4,5
            right--;
            for (int j = right; j >= left; j--)
                res[down][j] = ++index;  // 6,7
            down--;
            for (int i = down; i >= top; i--)
                res[i][left] = ++index;  // 8
            left++;
        }
        return res;
    }

private:
    void print(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};
