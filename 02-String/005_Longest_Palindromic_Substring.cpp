/*
Given a string s, find the longest palindromic substring in s. You may assume
that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        vector<vector<bool>> p(n, vector<bool>(n, false)); // -1 n/a; 0 false; 1 true
        int start, max = 1;
        for (int i = 0; i < n; i++)
            p[i][i] = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                p[i][i+1] = true;
                max = 2;
                start = i;
            } else {
                p[i][i+1] = false;
            }
        }
        int stride = 2;
        while (stride <= n - 1) {
            for (int j = 0; j + stride < n; j++) {
                if (p[j + 1][j + stride - 1] && (s[j] == s[j + stride])) {
                    p[j][j+stride] = true;
                    max = stride + 1;
                    start = j;
                }
            }
            stride++;
        }
        return s.substr(start, max);
    }
};
