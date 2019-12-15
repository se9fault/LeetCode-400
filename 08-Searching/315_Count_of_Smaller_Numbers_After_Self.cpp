/*
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller
elements to the right of nums[i].

Example:
Input: [5,2,6,1]
Output: [2,1,1,0]

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

// Insert Sort
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }
        return res;
    }
};
