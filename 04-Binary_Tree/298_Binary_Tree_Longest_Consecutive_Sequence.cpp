/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in
the tree along the parent-child connections. The longest consecutive path need
to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    /
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        dfs(root, root->val, 0, res);
        return res;
    }

private:
    void dfs(TreeNode *root, int v, int out, int &res) {
        if (root == nullptr)
            return;
        if (root->val == v + 1)
            ++out;
        else
            out = 1;
        res = max(res, out);
        dfs(root->left, root->val, out, res);
        dfs(root->right, root->val, out, res);
    }
};
