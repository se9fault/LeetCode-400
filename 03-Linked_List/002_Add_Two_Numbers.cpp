/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Solution: remember two linked list can be of different length, so need separate
check for nullptr
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *c = dummy, *c1 = l1, *c2 = l2;
        int carry = 0;
        while (c1 != nullptr || c2 != nullptr) {
            int val1 = (c1 != nullptr) ? c1->val : 0;
            int val2 = (c2 != nullptr) ? c2->val : 0;
            auto t = val1 + val2 + carry;
            c->next = new ListNode(t % 10);
            carry = t / 10;
            c = c->next;
            c1 = (c1 != nullptr) ? c1->next : nullptr;
            c2 = (c2 != nullptr) ? c2->next : nullptr;
        }
        if (carry) {
            c->next = new ListNode(1);
        }
        return dummy->next;
    }
};
