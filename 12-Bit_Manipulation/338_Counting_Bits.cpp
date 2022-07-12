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

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        vector<int> ans{0, 1};
        int k = 2, i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num)
                    break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t)
                    ans.push_back(ans[i - t]);
                else
                    ans.push_back(ans[i - t] + 1);
            }
            ++k;
        }
        return ans;
    }
};
