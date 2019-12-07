/*
You are given a perfect binary tree where all leaves are on the same level, and
every parent has two children. The binary tree has the following definition:
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space
for this problem.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next):
         val(_val), left(_left), right(_right), next(_next) {}
    }
};

*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        Node *prevLayer = root;

        while (prevLayer->left) {
            Node *p = prevLayer;
            while (p) {
                p->left->next = p->right;
                if (p->next) {
                    // use previous layer's next to connect this layer
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            prevLayer = prevLayer->left;
        }
        return root;
    }
};
