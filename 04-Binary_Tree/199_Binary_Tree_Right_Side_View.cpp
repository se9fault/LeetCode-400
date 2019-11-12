/*
Given a binary tree, imagine yourself standing on the right side of it, return
the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        AddToNodes(root, 0);
        vector<int> result;
        for (auto level : nodes) {
            result.push_back(level.back());
        }
        return result;
    }
private:
    vector<vector<int>> nodes;
    void AddToNodes(TreeNode *node, int depth) {
        if (node == nullptr)
            return;
        if (nodes.size() == depth) // the first guy in depth will init
            nodes.push_back(vector<int>());
        nodes[depth].push_back(node->val);
        AddToNodes(node->left, depth + 1); // actually DFS, with the help of depth
        AddToNodes(node->right, depth + 1);
    }
};
