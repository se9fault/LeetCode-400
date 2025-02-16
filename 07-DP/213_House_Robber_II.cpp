/*
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed. All houses at this place are arranged in
a circle. That means the first house is the neighbor of the last one. Meanwhile,
adjacent houses have security system connected and it will automatically contact
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each
house, determine the maximum amount of money you can rob tonight without
alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3
             (money = 2), because they are adjacent houses.

Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3

Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/

// Solution:
//   Use House Robber I twice: exclude last house (rob [0, n-2]), or exclude
//   first house (rob [1, n-1]), and use max.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

    int rob(vector<int>& nums, int low, int high) {
        int prevprev = 0, prev = 0, ans;
        for (int i = low; i <= high; ++i) {
            ans = max(prev, prevprev + nums[i]);
            prevprev = prev;
            prev = ans;
        }
        return ans;
    }
};
