/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the
array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

// Solutions:
// 1. Sort it. time O(NlogN), space O(1).
// 2. Create an unordered_set, and campare the size against the original vector.
//    time O(N), space O(N).
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                return true;
        }
        return false;
    }
};
