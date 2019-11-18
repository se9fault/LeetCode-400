/*
Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
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
            if (lower_bound(res.begin(), res.end(), temp) == res.end()) {
                res.push_back(temp);
                sort(res.begin(), res.end());
                return;
            } else {
                return;
            }
        }
        for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, target - nums[i], res, temp, i + 1);
            temp.pop_back();
        }
    }
};
