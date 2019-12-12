/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
            root = root->right;
        root->right = tmp;
    }
};
