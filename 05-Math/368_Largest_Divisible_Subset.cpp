/*
Given a set of distinct positive integers, find the largest subset such that
every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
Input: [1,2,3]      Output: [1,2] (of course, [1,3] will also be ok)

Example 2:
Input: [1,2,4,8]    Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);

        int m = 0, mi = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
        // iterate from end to start since it's easier to track the answer index
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
                    T[i] = 1 + T[j];
                    parent[i] = j;
                    if (T[i] > m) {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            ans.push_back(nums[mi]);
            mi = parent[mi];
        }
        // if we go by extending larger ends, the largest "answer" element will
        // come first since the candidate element we observe will become larger
        // and larger as i increases in the outermost "for" loop above.
        // alternatively, we can sort nums in decreasing order obviously.
        return ans;
    }
};
