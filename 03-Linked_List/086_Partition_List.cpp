/*
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two
partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessH(-1), moreH(-1);
        ListNode *less = &lessH, *more = &moreH, *cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                less->next = cur;
                cur = cur->next;
                less = less->next;
                less->next = nullptr;
            } else {
                more->next = cur;
                cur = cur->next;
                more = more->next;
                more->next = nullptr;
            }
        }
        less->next = moreH.next;
        return lessH.next;
    }
};
