/*
Given a set of distinct integers, nums, return all possible subsets (the power
set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size());
        vector<vector<int>> res(n, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n; j++) {
                if ((j >> i) & 1) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }

#ifdef BACKTRACK
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
            temp.push_back(nums[i]);
            backtrack(res, nums, temp, i + 1);
            temp.pop_back();
        }
	}
#endif
};
