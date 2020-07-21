/*
Given a binary tree, collect a tree's nodes as if you were doing this: Collect
and remove all leaves, repeat until the tree is empty.

Example:
Input: [1,2,3,4,5]
          1
         / \
        2   3
       / \
      4   5
Output: [[4,5,3],[2],[1]]

Explanation:
1. Removing the leaves [4,5,3] would result in this tree:
          1
         /
        2
2. Now removing the leaf [2] would result in this tree:
          1
3. Now removing the leaf [1] would result in the empty tree:
          []

Solution: DFS, use self-defined depth here.
*/

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }

private:
    int helper(TreeNode* node, vector<vector<int>>& ans) {
        if (node == nullptr)
            return -1;
        // leaf node depth will be 0, because nullptr is -1
        int depth = 1 + max(helper(node->left, ans), helper(node->right, ans));
        if (depth >= ans.size())
            ans.resize(depth + 1);
        ans[depth].push_back(node->val);
        return depth;
    }
};
