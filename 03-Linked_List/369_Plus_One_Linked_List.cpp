/*
Given a non-negative integer represented as non-empty a singly linked list of
digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0
itself.
The digits are stored such that the most significant digit is at the head of the
list.

Example :
Input: [1,2,3]
Output: [1,2,4]

Solution: reverse the linked list, add 1 (carry all the way), reverse back
*/

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *rev = reverse(head), *cur = rev, *pre = rev;
        int carry = 1; // the initial 1 being added
        while (cur) {
            pre = cur;
            cur->val += carry;
            carry = (cur->val / 10);
            cur->val %= 10;
            if (carry == 0)
                break;
            cur = cur->next;
        }
        if (carry)
            pre->next = new ListNode(1);
        return reverse(rev);
    }

private:
    ListNode* reverse(ListNode *head) {
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
