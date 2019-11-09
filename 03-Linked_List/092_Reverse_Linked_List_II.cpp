/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 1-2-3-4-5, m=2, n=4, result 1-4-3-2-5
        ListNode dummy(0), *prev = &dummy, *cur;
        dummy.next = head;
        for (int i = 0; i < m - 1; i++) {
            prev = prev->next;
            // (the reverse area is from m to n) prev is the before-m element
        }

        cur = prev->next; // cur 每次都在reverse区的末尾，也就是remain区域之前
        // every time, put one after prev.
        // 1st time: 1-> {[2]} - (3-4) ->5         {}: new moved    []: reversed    (): remain
        // 2nd time: 1-> [{3}-2] - (4) ->5
        // 3rd time: 1-> [{4}-3-2]     ->5
        for (int i = 0; i < n - m; i++) {
            auto temp = prev->next; // 保存reverse区原开头
            prev->next = cur->next; // 每次拿remain区域的第一个，放在reverse区域开头
            cur->next = cur->next->next; // 让reverse区域后面跟着的，变成remain区域的第二个
            prev->next->next = temp; // 让新移动的节点的next指向reverse区域的原开头
        }
        return dummy.next;
    }
};
