/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down.
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is
not allowed).

Example 1:
Input: nums =
[ [9,9,4],
  [6,6,8],
  [2,1,1] ]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: nums =
[ [3,4,5],
  [3,2,6],
  [2,2,1] ]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
not allowed.
*/

class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int helper(vector<vector<int>> & matrix, vector<vector<int>> & dp, int i, int j) {
        if (!isValid(i, j, matrix.size(), matrix[0].size()))
            return 0;
        if (dp[i][j] > -1)
            return dp[i][j];
        int ans = 1;
        for (auto &it : dir)
            if (isValid(i + it.first, j + it.second, matrix.size(), matrix[0].size()) && matrix[i + it.first][j + it.second] > matrix[i][j])
                ans = max(ans, 1 + helper(matrix, dp, i + it.first, j + it.second));
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                ans = max(ans, helper(matrix, dp, i, j));
        return ans;
    }
};
