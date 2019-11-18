/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[ [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1] ]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, nums);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, vector<int> &temp,
                   vector<int> &nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isNotInVector(temp, nums[i])) {
                temp.push_back(nums[i]);
                backtrack(res, temp, nums);
                temp.pop_back();
            }
        }
    }

    template <typename T>
    bool isNotInVector(vector<T> &vec, T target) {
        for (auto it = vec.begin(); it != vec.end(); it++)
            if (*it == target)
                return false;
        return true;
    }
};
