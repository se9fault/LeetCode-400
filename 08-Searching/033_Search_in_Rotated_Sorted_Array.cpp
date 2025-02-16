/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index,
otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

// Time Complexity: O(logN)
// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        // solution space [low, high]

        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool same_side = (nums[mid] >= nums[0]) == (target >= nums[0]);
            if (nums[mid] > target) {
                if (same_side) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                if (same_side) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] == target) {
                return mid;
            }
        }
        return -1; // solution space ∅
    }
};
