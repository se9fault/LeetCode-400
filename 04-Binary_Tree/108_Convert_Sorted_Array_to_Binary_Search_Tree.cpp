/*
Given an array where elements are sorted in ascending order, convert it to a
height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
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
using iter = vector<int>::const_iterator;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        return buildBST(nums.begin(), nums.end());
    }
private:
    TreeNode* buildBST(iter begin, iter end) {
        if (begin >= end)
            return nullptr;
        iter mid = begin + (end - begin) / 2;
        TreeNode* node = new TreeNode(*mid); // 取值
        node->left = buildBST(begin, mid);
        node->right = buildBST(mid + 1, end);
        return node;
    }
};
