/*
Given a set of candidate numbers (candidates) (without duplicates) and a target
number (target), find all unique combinations in candidates where the candidate
numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of
times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, target, res, temp, 0);
        return res;
    }
private:
    void backtrack(vector<int> &nums, int target, vector<vector<int>> &res,
                   vector<int> &temp, int begin) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, target - nums[i], res, temp, i);
            temp.pop_back();
        }
    }
};
