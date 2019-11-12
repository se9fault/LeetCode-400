/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?
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
#define iterative
#ifdef recursive
private:
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalStep(root);
        return result;
    }
    void inorderTraversalStep(TreeNode *node) {
        if (node == nullptr)
            return;
        inorderTraversalStep(node->left);
        result.push_back(node->val);
        inorderTraversalStep(node->right);
    }
#endif

#ifdef iterative
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur -> left;
            } else {
                cur = s.top();
                s.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
#endif
};
