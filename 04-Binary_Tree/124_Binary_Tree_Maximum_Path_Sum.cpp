/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting
node to any node in the tree along the parent-child connections. The path must
contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]
       1
      / \
     2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
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
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN; // numeric_limits<int>::min();
        maxPathAndGlobalUpdate(root, max);
        return max;
    }
private:
    int maxPathAndGlobalUpdate(TreeNode *root, int& global_max) {
        if (root == nullptr)
            return 0;
        int l = max(0, maxPathAndGlobalUpdate(root->left, global_max));
        int r = max(0, maxPathAndGlobalUpdate(root->right, global_max));
        global_max = max(global_max, l + r + root->val); // 更新的是一整条路径，左+自己+右
        return root->val + max(l, r); // 返回值作为一边的最大值
    }
};
