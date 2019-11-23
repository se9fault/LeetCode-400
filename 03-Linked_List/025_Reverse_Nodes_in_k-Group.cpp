/*
Given a linked list, reverse the nodes of a linked list k at a time and return
its modified list.

k is a positive integer and is less than or equal to the length of the linked
list. *If the number of nodes is not a multiple of k then left-out nodes in the
end should remain as it is.*

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be
changed.
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *prev = &dummy, *last;
        dummy.next = head;
        
        // 0       -> 1 -> 2      -> 3 -> 4 -> 5, k = 2, swapping 1->2
        // ^prev           ^last
        while (prev->next != nullptr) {
            last = prev;
            int i;
            for (i = 0; i < k && last->next != nullptr; ++i) {
                last = last->next;
            }
            if (i != k)
                break; // don't change the remain, as problem suggest
            auto newLast = prev->next;
            auto lastNext = last->next;
            prev->next = reverse(prev->next, last);
            prev = newLast;
            newLast->next = lastNext;
        }

        return dummy.next;
    }

private:
    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode *cur = first, *newHead = nullptr;
        while (cur != last) {
            auto temp = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = temp;
        }
        last->next = newHead;
        return last;
    }
    void print(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            printf("%d->", cur->val);
            cur = cur->next;
        }
        printf("nullptr\n");
        return;
    }
};
