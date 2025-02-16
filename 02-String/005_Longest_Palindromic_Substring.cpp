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

class Solution {
// expand from the middle (2n-1 middles), time O(N^2), Optimize: manacher
public:
    string longestPalindrome(string s) {
        int maxStart = 0, maxLength = 1; // store ans
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            expand(s, n, i, i, maxStart, maxLength);
            expand(s, n, i, i + 1, maxStart, maxLength);
        }
        return s.substr(maxStart, maxLength);
    }

    void expand(string &s, int n, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j <= n - 1 && s[i] == s[j]) {
            --i;
            ++j;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }
};
