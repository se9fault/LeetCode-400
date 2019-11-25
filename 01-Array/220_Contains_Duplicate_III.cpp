/*
Given an array of integers, find out whether there are two distinct indices i
and j in the array such that the absolute difference between nums[i] and nums[j]
is at most t and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

// using bucket sort, time: O(n); space: O(n)
class Solution {
    long long getBucketId(long long i, long long w) {
        return i < 0 ? (i + 1) / w - 1 : i / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k < 1 || t < 0)
        {
            return false;
        }

        unordered_map<long long, long long> buckets;
        long long width = (long long)t + 1;
        for (int i = 0; i < n; i++)
        {
            long long id = getBucketId(nums[i], width);

            // found the value in the same bucket
            if (buckets.find(id) != buckets.end())
            {
                return true;
            }

            // found the value in the adjacent bucket
            if ((buckets.find(id - 1) != buckets.end() && nums[i] - buckets[id - 1] < width) ||
                (buckets.find(id + 1) != buckets.end() && buckets[id + 1] - nums[i] < width))
            {
                return true;
            }

            // insert current value to buckets
            buckets[id] = nums[i];

            if (i >= k)    // remove out of range element
            {
                buckets.erase(getBucketId(nums[i - k], width));
            }
        }

        return false;
    }
};
