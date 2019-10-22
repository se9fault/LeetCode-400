class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); // for n numbers, the return value must be in [1, n+1].
        for (int i = 0; i < n; i++) {
            // we put every number in the right place, like put 5 at nums[4].
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]); // nums[i] should be at location nums[i] - 1
        }

        // return the first place where the number isn't right.
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};