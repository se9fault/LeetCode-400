/*
Given a nested list of integers, return the sum of all integers in the list
weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be
integers or other lists.

Different from the previous question where weight is increasing from root to
leaf, now the weight is defined from bottom up. i.e., the leaf level integers
have weight 1, and the root level integers have the largest weight.

Example 1:
Input: [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's at depth 1, one 2 at depth 2.

Example 2:
Input: [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1;
1*3 + 4*2 + 6*1 = 17.
*/

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int res = 0;
        vector<int> v;
        for (auto &a : nestedList)
            helper(a, 0, v);
        for (int i = (int)v.size() - 1; i >= 0; --i)
            res += v[i] * ((int)v.size() - i);
        return res;
    }
private:
    void helper(NestedInteger& ni, int depth, vector<int>& v) {
        if (depth >= v.size())
            v.resize(depth + 1);
        if (ni.isInteger()) {
            v[depth] += ni.getInteger();
        } else {
            for (auto &a : ni.getList()) {
                helper(a, depth + 1, v);
            }
        }
    }
};
