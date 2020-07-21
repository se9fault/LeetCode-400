/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You may not modify the values in the list's nodes, only nodes itself may be
changed.

Example 1: Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2: Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

class Solution {
public:
    void reorderList (ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // let slow be at the half of linked list, 1->2->(3)->4->5
        ListNode *c1 = head, *c2 = reverseList(slow->next);
        slow->next = nullptr;
        // c1: 1->2->3    c2: 5->4

        while (c2 != nullptr) {
            auto temp = c1->next;
            c1->next = c2;
            c2 = c2->next;
            c1->next->next = temp;
            c1 = temp;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head, *newHead = nullptr;
        while (cur != nullptr) {
            auto temp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = temp;
        }
        return newHead;
    }
};
