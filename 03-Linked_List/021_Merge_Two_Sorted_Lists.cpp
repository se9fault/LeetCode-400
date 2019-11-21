/*
Merge two sorted linked lists and return it as a new list. The new list should
be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *c = dummy, *c1 = l1, *c2 = l2;
        while (c1 != nullptr || c2 != nullptr) {
            if ((c1 != nullptr && c2 != nullptr && c1->val < c2->val) || (c2 == nullptr)) {
                c->next = c1;
                c1 = c1->next;
                c = c->next;
                c->next = nullptr;
            } else {
                c->next = c2;
                c2 = c2->next;
                c = c->next;
                c->next = nullptr;
            }
        }
        return dummy->next;
    }
};
