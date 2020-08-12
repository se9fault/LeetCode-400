/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Example:
Input:
   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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

// Solution:
// Recursion to the fullest; not backtracking because didn't undo any step
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        binaryTreePaths(root, results, "");
        return results;
    }
private:
    void binaryTreePaths(TreeNode* root, vector<string>& results, string cur) {
        if (root == nullptr)
            return;
        cur += std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            results.push_back(cur);
            return;
        }
        cur += "->";
        binaryTreePaths(root->left, results, cur);
        binaryTreePaths(root->right, results, cur);
    }
};
