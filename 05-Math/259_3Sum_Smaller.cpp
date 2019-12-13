/*
Given an array of n integers nums and a target, find the number of index
triplets i, j, k with 0 <= i < j < k < n that satisfy the condition
nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]

Follow up:
Could you solve it in O (n^2) runtime?
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    ans += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
