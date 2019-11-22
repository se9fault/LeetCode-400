/*
Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int minGap = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i + 1;
                int high = nums.size() - 1;

                while (low < high) {
                    int sum = nums[i] + nums[low] + nums[high];
                    int gap = abs(sum - target);
                    if (gap < minGap) {
                        minGap = gap;
                        result = sum;
                    }
                    if (sum < target) {
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return result;
    }
};
