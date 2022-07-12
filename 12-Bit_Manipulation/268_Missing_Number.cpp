/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Constraints:
  n == nums.length
  1 <= n <= 10^4
  0 <= nums[i] <= n
  All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space complexity
and O(n) runtime complexity?
*/


// Solution:
//   Use the property of XOR. XOR is its own inverse, so a number XORed twice
//   would be canceled out. We XOR all nums and [0,n], then the missing number
//   would be XORed only once.
// Follow-up:
//   If the original array is sorted, then we can use binary search: if the
//   value is bigger than the index, then the missing value is on the left.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), missing = n; // XOR n first
        for (int i = 0; i < n; i++) {
            missing ^= i ^ nums[i]; // XOR [0, n-1] and nums
        }
        return missing;
    }
};
