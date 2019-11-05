// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int n : nums) {
            if (n != nums[i]) {
                nums[++i] = n;
            }
        }
        return i + 1;
    }
};
