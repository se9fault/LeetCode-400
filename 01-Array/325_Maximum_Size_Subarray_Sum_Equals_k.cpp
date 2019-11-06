/*
Given an array nums and a target value k, find the maximum length of a subarray that sums
to k. If there isn't one, return 0 instead.
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer
range.

Example1
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 ([1, -1, 5, -2])

Example2
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 ([-1, 2])

Challenge
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, ans = 0;
        // (sum value starting from 0, the earliest idx that hit this sum)
        m[0] = -1; // the first sum as 0 is the place before [0], so -1
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
            if (m.find(sum - k) != m.end()) {
                ans = max(ans, i - m[sum - k]);
            }
        }
        for (auto i : m) {
            printf("%d %d\n", i.first, i.second);
        }
        return ans;
    }
};
