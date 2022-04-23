/*
Given an array of integers and an integer k, find out whether there are two
distinct indices i and j in the array such that nums[i] = nums[j] and the
absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> nmap;
        // stores (num, the last position num appeared)
        for (int i = 0; i < nums.size(); ++i) {
            if (nmap.find(nums[i]) == nmap.end())
                nmap[nums[i]] = i;
            else if (i - nmap[nums[i]] <= k)
                return true;
            else
                nmap[nums[i]] = i;
        }
        return false;
    }
};
