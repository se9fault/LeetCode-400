/*
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[ [3], [9,20],[15,7] ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        vector<int> row;
        std::list<TreeNode*> list;
        list.push_back(root);
        list.push_back(nullptr);
        while (list.size() > 1) {
            auto cur = list.front();
            list.pop_front();
            if (cur != nullptr) {
                row.push_back(cur->val);
                if (cur->left)
                    list.push_back(cur->left);
                if (cur->right)
                    list.push_back(cur->right);
            } else {
                result.push_back(row);
                row.clear();
                list.push_back(nullptr);
            }
        }
        result.push_back(row);
        return result;
    }
};
