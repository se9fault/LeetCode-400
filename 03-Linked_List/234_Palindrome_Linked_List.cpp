/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome (ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // let slow be at the half of linked list, 1->2->(3)->4->5
        slow->next = reverseList(slow->next);
        // reverse 2nd half, 1->2->(3)->5->4

        slow = slow->next; // (1)->2->3->(5)->4
        while (slow != nullptr) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
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
