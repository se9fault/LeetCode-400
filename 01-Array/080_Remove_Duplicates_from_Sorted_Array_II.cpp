/*
Given a sorted array nums, remove the duplicates in-place such that duplicates
appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.
It doesn't matter what you leave beyond the returned length.

Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3 respectively.

Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums
being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

Constraints:
    1 <= nums.length <= 3 * 10^4
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
*/

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};