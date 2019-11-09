/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0), *cur = head, *prev = dummy;
        dummy->next = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                continue;
            }
            cur = cur->next;
            prev = prev->next;
        }
        return dummy->next;
    }
};
