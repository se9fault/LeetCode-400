/*
Given an unsorted array of integers, find the length of longest increasing
subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.

Note:
There may be more than one LIS combination, it is only necessary for you to
return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < dp.size(); ++i) {
            int max_dp_j = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // dp[j] 的一串，接上 nums[i] 是递增的
                    max_dp_j = max(max_dp_j, dp[j]);
                }
            }
            dp[i] = max_dp_j + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
