/*
Given a non-empty binary search tree and a target value, find the value in the
BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to
the target.
*/

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        TreeNode *t = target < a ? root->left : root->right;
        if (t == nullptr)
            return a;
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};
