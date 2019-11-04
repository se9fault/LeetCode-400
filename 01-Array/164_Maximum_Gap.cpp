/*
Given an unsorted array, find the maximum difference between the successive
elements in its sorted form.

Return 0 if the array contains less than 2 elements.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;

        sort(nums.begin(), nums.end());                 // sort the array

        int maxGap = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);
        return maxGap;
    }
};
\

/*
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // x: idx of bucket   y: 0: min of bucket   1: max of bucket
        vector<vector<int>> buckets(nums.size() + 1, vector<int>(2, 0));
        for (int i = 0; i < buckets.size(); ++i) {
            buckets[i][0] = INT_MAX;
            buckets[i][1] = INT_MIN;
        }
        
        int min = INT_MAX, max = INT_MIN;
        for (int num : nums) {
            max = (num > max) ? num : max;
            min = (num < min) ? num : min;
        }
        int k = (max - min) / (nums.size() + 1) + 1 ;
        for (int num : nums) {
            int idx = num / k;
            printf("%d\n", idx);
            buckets[idx][0] = num < buckets[idx][0] ? num : buckets[idx][0];
            buckets[idx][1] = num > buckets[idx][0] ? num : buckets[idx][1];
        }
        
        int result = INT_MIN;
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i][1] - buckets[i][0] > result)
                result = buckets[i][1] - buckets[i][0];
            if (i > 0 && buckets[i][0] - buckets[i-1][1] > result)
                result = buckets[i][0] - buckets[i-1][1];
        }
        return result;
    }
}; 
*/
