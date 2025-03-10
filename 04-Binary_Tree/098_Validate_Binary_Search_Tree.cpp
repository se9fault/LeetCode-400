/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's
key.
The right subtree of a node contains only nodes with keys greater than the
node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
    2
   / \
  1   3
Input: [2,1,3]
Output: true

Example 2:
    5
   / \
  1   4
     / \
    3   6
Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    bool isValidBST(TreeNode* root) {
        // solution: BST's inorder traversal is in order
        int inOrder = INT_MIN;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while (!s.empty() || cur != nullptr) {
            if (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                if (cur->val <= inOrder)
                    return false;
                inOrder = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }

    bool isValidBST_solution_2(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    // cannot store min/max as INT_MIN / INT_MAX, as they may be used as values
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) {
            return true;
        }
        int val = root->val;
        if (min && val <= min->val) {
            return false;
        }
        if (max && val >= max->val) {
            return false;
        }
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};