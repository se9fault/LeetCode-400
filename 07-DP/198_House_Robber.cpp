/*
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security system connected and
it will automatically contact the police if two adjacent houses were broken into
on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
             (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        /* f(n) = 0, n < 0
                  max(f(n-1), f(n-2) + nums[n]), 0 ≤ n < nums.size()
                  (the maximum amount we get when robbing houses [0, n])
        Note: If we choose to rob house n, we get f(n-2) + nums[n]; if not, we
              get f(n-1). It has nothing to do with whether f(n-1) robs house
              n-1 or not.
        */
        int n = nums.size(), prevprev = 0, prev = 0, ans;
        for (int i = 0; i < n; ++i) {
            ans = max(prev, prevprev + nums[i]);
            prevprev = prev;
            prev = ans;
        }
        return ans;
    }
};
