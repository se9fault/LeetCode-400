/*
Given an array nums, there is a sliding window of size k which is moving from the very left of
the array to the very right. You can only see the k numbers in the window. Each time the
sliding window moves right by one position. Return the max element in every sliding window.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]

Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Solution:
monotonic queue, stores index, maintain from head->tail, always big->small.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // monotonic queue, stores index, head->tail big->small
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front(); // L++
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();  // maintain monotonic queue, head->tail always >
            dq.push_back(i);    // R++
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]); // don't push immature windows
        }
        return ans;
    }
};
