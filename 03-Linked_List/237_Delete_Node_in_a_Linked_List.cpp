/*
Write a function to delete a node (except the tail) in a singly linked list,
given only access to that node.

Note:
The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the
linked list.
Do not return anything from your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // move the value of next node to this node, delete next node
        auto temp = node->next;
        node->val = temp->val;
        node->next = temp->next; // or *node = *temp
        delete temp;
    }
};
