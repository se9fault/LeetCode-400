/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be
changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy{-1, head};
        ListNode *cur = &dummy;
        // cur always points to the element before pairs, like (dummy)->1->2->3, d->2->(1)->3
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            temp->next = temp->next->next;
            cur->next->next = temp;
            cur = temp;
        }
        return dummy.next;
    }
};
