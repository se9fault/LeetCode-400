/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:    Input: [1,2,0]          Output: 3
Example 2:    Input: [3,4,-1,1]       Output: 2
Example 3:    Input: [7,8,9,11,12]    Output: 1

Note: Your algorithm should run in O(n) time and uses constant extra space.
*/

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // for n numbers, the return value must be in [1, n+1].
        for (int i = 0; i < n; i++) {
            // we put every number in the right place, like put 5 at nums[4].
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
                // nums[i] should be at location nums[i] - 1
        }

        // return the first place where the number isn't right.
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
