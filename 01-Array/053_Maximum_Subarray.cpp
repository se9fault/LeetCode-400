/*
Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.
*/

// Solution: greedy / DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], ans = nums[0], n = nums.size();
        for (int i = 1; i < n; ++i) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};
