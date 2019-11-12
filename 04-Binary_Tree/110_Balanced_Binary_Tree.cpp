/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in
height by no more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto res = isItBalanced(root);
        return res.b;
    }
private:
    struct result {
        bool b;
        int height;
    }; // can also use some height value to indicate false, like -1
    result isItBalanced(TreeNode* root) {
        if (root == nullptr) {
            return result{true, 0};
        }
        auto left = isItBalanced(root->left);
        if (!left.b)
            return result{false, 0};
        auto right = isItBalanced(root->right);
        if (!right.b)
            return result{false, 0};
        if (abs(left.height - right.height) > 1)
            return result{false, 0};
        return result{true, max(left.height, right.height) + 1};
    }
};
