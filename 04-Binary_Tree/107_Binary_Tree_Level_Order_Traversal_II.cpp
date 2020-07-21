/*
Given a binary tree, return the bottom-up level order traversal of its nodes'
values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[ [15,7], [9,20], [3] ]
*/

class Solution {
private:
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (node == nullptr)
            return;
        ans[level].push_back(node->val);
        levelOrder(ans, node->left, level - 1);
        levelOrder(ans, node->right, level - 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d,vector<int> {});
        levelOrder(ans, root, d - 1);
        return ans;
    }
};
