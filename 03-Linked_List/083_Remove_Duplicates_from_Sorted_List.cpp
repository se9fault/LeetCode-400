/*
Given a sorted linked list, delete all duplicates such that each element appear
only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* runner = cur->next;
            while (runner != nullptr && runner->val == cur->val) {
                runner = runner->next;
                // maybe some linked list for GC here :)
            }
            cur->next = runner;
            cur = cur->next;
        }
        return head;
    }
};
