/*
Given a binary tree
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
    Node *connect(Node *root) {

        Node *head = nullptr; // head of the next level
        Node *prev = nullptr; // the leading node on the next level
        Node *cur = root;     // current node of current level

        while (cur != nullptr) {

            while (cur != nullptr) { // iterate on the current level
                // left child
                if (cur->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                // right child
                if (cur->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                // move to next node
                cur = cur->next;
            }

            // move to next level
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }
};
