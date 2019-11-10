/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]

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
public:
    vector<int> postorderTraversal(TreeNode* root) { // left -> right -> mid
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<TreeNode*> stack, pstack;
        stack.push(root);
        while (!stack.empty()) {
            auto cur = stack.top();
            stack.pop();
            pstack.push(cur);
            if (cur->left)
                stack.push(cur->left);
            if (cur->right)
                stack.push(cur->right);
        }
        while (!pstack.empty()) {
            result.push_back(pstack.top()->val);
            pstack.pop();
        }
        return result;
    }
};
