/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[ [1,1,2],
  [1,2,1],
  [2,1,1] ]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> takers(nums.size(), false);
        backtrack(res, temp, nums, takers);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, vector<int> &temp,
                   vector<int> &nums, vector<bool> &takers) {
        if (temp.size() == nums.size()) {
            if (isNotInVector(res, temp)) {
                res.push_back(temp);
                return;
            } else {
                return;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!takers[i]) {
                temp.push_back(nums[i]);
                takers[i] = true;
                backtrack(res, temp, nums, takers);
                temp.pop_back();
                takers[i] = false;
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
