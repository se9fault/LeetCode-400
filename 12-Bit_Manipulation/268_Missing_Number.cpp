/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it
using only constant extra space complexity?

Solution:
  Use the property of XOR. A number that got XORed twice will be canceled out.
  Therefore we can XOR [0, n], and also XOR the array. Then the missing number
  only got XORed once.

Follow-up:
  If the original array is sorted, then we can use binary search: if the value
  is bigger than the index, then the missing value is on the left.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // XOR n first, because loop's exit condition is written this way
        int n = nums.size(), missing = n;
        for (int i = 0; i < n; i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};
