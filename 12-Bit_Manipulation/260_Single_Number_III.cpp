/*
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice. Find the two elements that
appear only once.

Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:
The order of the result is not important. So in the above example, [5, 3] is
also correct.
Your algorithm should run in linear runtime complexity. Could you implement it
using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2
        vector<int> ans = {0, 0};
        for (int num : nums) {
            if ((num & diff) == 0) { // the bit is not set
                ans[0] ^= num;
            } else {                 // the bit is set
                ans[1] ^= num;
            }
        }
        return ans;
    }
};
