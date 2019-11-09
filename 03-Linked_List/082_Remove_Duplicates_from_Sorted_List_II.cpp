/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
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
        ListNode dummy(-1), garbage(-1);
        dummy.next = head;
        garbage.next = nullptr;
        ListNode* cur = head, *prev = &dummy, *gcCur = &garbage;
        // cur always points to the node currently being inspected as the
        // candidate for deletion, like d->(1)->1->2->3, d->(2)->3
        while (cur != nullptr) {
            ListNode* runner = cur;
            while (runner->next != nullptr && runner->next->val == cur->val) {
                runner = runner->next;
            }
            if (runner == cur) {
                // no need to delete
                prev = cur;
                cur = cur->next;
            } else {
                gcCur->next = prev->next; // gc
                prev->next = runner->next; // delete all in [cur, runner]
                cur = runner->next;
                runner->next = nullptr; // gc
            }
        }
        // gc
        cur = garbage.next;
        while (cur != nullptr) {
            auto temp = cur->next;
            delete cur;
            cur = temp;
        }
        return dummy.next;
    }
};
