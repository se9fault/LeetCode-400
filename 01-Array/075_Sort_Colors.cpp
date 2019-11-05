/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of
the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue
respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total
number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, lo = 0, hi = nums.size() - 1;
        // invariants: nums[0..lo-1] are less than pivot 1, nums[lo..i-1] equal,
        //   nums[hi+1..end] greater
        while (i <= hi)
            if (nums[i] < 1)
                swap(nums[i++], nums[lo++]);
            else if (nums[i] > 1)
                swap(nums[i], nums[hi--]);
            else
                // only swap when met 0 or 2, 1 will eventually be in place
                i++;
    }
};
