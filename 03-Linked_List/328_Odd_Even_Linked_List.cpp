/*
Given a singly linked list, group all odd nodes together followed by the even
nodes. Please note here we are talking about the node number and not the value
in the nodes.

You should try to do it in place. The program should run in O(1) space
complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was
in the input.
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode odd(-1), even(-1);
        ListNode *curOdd = &odd, *curEven = &even; // always point to the end, so just append
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            // process two at a time, cur always points to the first one in pair
            curOdd->next = cur;
            curEven->next = cur->next;
            cur = cur->next->next;
            curOdd = curOdd->next;
            curOdd->next = nullptr;
            curEven = curEven->next;
            curEven->next = nullptr;
        }
        if (cur != nullptr) { // if one last odd
            curOdd->next = cur;
            curOdd = curOdd->next;
        }
        curOdd->next = even.next; // still, "even" is a dummy
        return odd.next;
    }
};
