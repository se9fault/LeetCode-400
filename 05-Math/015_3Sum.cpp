/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // O(NlogN)
        std::sort(nums.begin(), nums.end());

        // O(N^2), look at the numbers behind nums[i]
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                break; // if nums[i] > 0, then no way to hit the target (nums[i + k] > nums[i])
            }
            int target = -nums[i];
            int front = i + 1;
            int back = n - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target) {
                    ++front;
                } else if (sum > target) {
                    --back;
                } else {
                    vector<int> result{nums[i], nums[front], nums[back]};
                    ans.push_back(result);

                    // Processing duplicates of Number 2
                    while (front < back && nums[front] == result[1]) {
                        ++front;
                    }
                    // Processing duplicates of Number 3
                    while (front < back && nums[back] == result[2]) {
                        --back;
                    }
                }
            }

            // Processing duplicates of Number 1
            while (i + 1 < n && nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return ans;
    }
};