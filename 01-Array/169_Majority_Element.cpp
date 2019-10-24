class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
            // even in [1, 2 ,1, 3, 1, 4, 1], the candidate is set to the last 1
        }
        return candidate;
    }
};