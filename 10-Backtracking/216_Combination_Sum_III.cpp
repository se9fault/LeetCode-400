/*
Find all possible combinations of k numbers that add up to a number n, given
that only numbers from 1 to 9 can be used and each combination should be a
unique set of numbers.

Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // int candidates = 1;
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(k, n, res, temp, 1);
        return res;
    }
private:
    void backtrack(int counts, int target, vector<vector<int>> &res,
                   vector<int> &temp, int begin) {
        if (target == 0 && counts == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = begin; i <= 9 && target >= i && counts > 0; i++) {
            temp.push_back(i);
            backtrack(counts - 1, target - i, res, temp, i + 1);
            temp.pop_back();
        }
    }
};
