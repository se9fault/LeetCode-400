/*
Write a program to find the node at which the intersection of two singly linked
lists begins.

Example 1:
   4->1--|
5->0->1->8->4->5
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5]
Output: Reference of the node with value = 8

Example 2:
0->9->1->2->4
      3--|
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4]
Output: Reference of the node with value = 2

Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5]
Output: null
Explanation: The two lists do not intersect, so return null.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function
returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *curA = headA, *curB = headB;
        for ( ; curA->next != nullptr; lenA++)
            curA = curA->next;
        for ( ; curB->next != nullptr; lenB++)
            curB = curB->next;
        if (curA != curB)
            return nullptr;

        curA = headA;
        curB = headB;
        int diff = lenA - lenB;
        if (diff > 0) {
            for (int i = 0; i < diff; i++)
                curA = curA->next;
        } else {
            for (int i = 0; i < -diff; i++)
                curB = curB->next;
        }
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};
