/*
Given a collection of integers that might contain duplicates, nums, return all
possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, nums, temp, 0);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, vector<int> &nums,
                   vector<int> &temp, int begin) {
        res.push_back(temp);
        for (int i = begin; i != nums.size(); ++i) {
            if (i == begin || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                backtrack(res, nums, temp, i + 1);
                temp.pop_back();
            }
        }
    }
};
