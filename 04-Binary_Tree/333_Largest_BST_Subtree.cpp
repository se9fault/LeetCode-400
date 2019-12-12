/*
Given a binary tree, find the largest subtree which is a Binary Search Tree
(BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:    Input: [10,5,15,1,8,null,7]    Output: 3
   10
   / \
  5  15
 / \   \
1   8   7

Explanation: The Largest BST Subtree in this case is the highlighted one. The
return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (isValid(root, INT_MIN, INT_MAX))
            return count(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

private:
    bool isValid(TreeNode* root, int mn, int mx) {
        if (root == nullptr)
            return true;
        if (root->val <= mn || root->val >= mx)
            return false;
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
    int count(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return count(root->left) + count(root->right) + 1;
    }
};
