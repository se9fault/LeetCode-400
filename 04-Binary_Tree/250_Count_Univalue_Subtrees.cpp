/*
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.

Solution: recursive, bottom-up solution
*/

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        isUnival(root, -1, ans);
        return ans;
    }
private:
    int isUnival(TreeNode* root, int val, int &ans) {
        if (root == nullptr)
            return true;
        if (!isUnival(root->left, root->val, ans) | !isUnival(root->right, root->val, ans))
            return false;
        ++ans;
        return root->val == val;
    }
};
