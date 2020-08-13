/*
Given a sorted positive integer array nums and an integer n, add/patch elements
to the array such that any number in range [1, n] inclusive can be formed by the
sum of some elements in the array. Return the minimum number of patches
required.

Example 1:
Input: nums = [1,3], n = 6        Output: 1
Explanation: Combinations of nums are [1], [3], [1,3], which form possible sums
of: 1, 3, 4. Now if we add/patch 2 to nums, the combinations are: [1], [2], [3],
[1,3], [2,3], [1,2,3]. Possible sums are 1, 2, 3, 4, 5, 6, which now covers the
range [1, 6]. So we only need 1 patch.

Example 2:
Input: nums = [1,5,10], n = 20    Output: 2
Explanation: The two patches can be [2, 4].

Example 3:
Input: nums = [1,2,2], n = 5      Output: 0

Solution: time O(n), space O(1), greedy
*/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, added = 0, i = 0;
        // miss: the smallest sum we might be missing -> [0, miss) can be built
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
                // since we can build [0, miss), adding nums[i] allow us
                // to build [nums[i], miss + nums[i])
            } else {
                // nums[i] > miss, miss is actually missed, we need to pad.
                // Pad miss itself is the greedy way
                miss += miss;
                added++;
            }
        }
        return added;
    }
};
