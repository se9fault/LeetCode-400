/*
Given an integer n, return an array `ans` of length n + 1 such that for each i
(0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:    Input: 2    Output: [0,1,1]
Example 2:    Input: 5    Output: [0,1,1,2,1,2]

Constraints:  0 <= n <= 10^5

Follow up:
1. It is very easy to come up with a solution with a runtime of O(NlogN). Can
you do it in linear time O(n) and possibly in a single pass?
2. Can you do it without using any built-in function (i.e., like
`__builtin_popcount` in C++)?
*/

// Solution:
//   DP; to calculate f(n), reuse the result of f(n/2).
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            results[i] = results[i >> 1] + (i & 1);
        }
        return results;
    }
};
