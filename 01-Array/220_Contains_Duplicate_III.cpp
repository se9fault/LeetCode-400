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