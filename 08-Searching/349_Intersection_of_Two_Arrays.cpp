/*
Given two arrays, write a function to compute their intersection.

Example 1:    Input: nums1 = [1,2,2,1], nums2 = [2,2]        Output: [2]
Example 2:    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]    Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return vector<int>();
        }
        unordered_set<int> set{nums1.cbegin(), nums1.cend()};
        vector<int> res;
        for (auto n: nums2) {
            if (set.erase(n) > 0) {
            // if n exists in set, then 1 is returned and n is erased; otherwise, 0.
                res.push_back(n);
            }
        }
        return res;
    }
};
