/*
Given a linked list, return the node where the cycle begins. If there is no
cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which
represents the position (0-indexed) in the linked list where tail connects to.
If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list.


Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the
second node.
3 -> 2 -> 0 -> -4 |
^                 |
|-----------------|

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the
first node.
1 -> 2|
^     |
|-----|

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Follow-up:
Can you solve it without using extra space?
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return detectCycle_hash_table(head);
    }

    ListNode *detectCycle_hash_table(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode *cur = head;
        while (cur != nullptr) {
            if (set.find(cur) != set.end())
                return cur;
            set.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }

    ListNode *detectCycle_fast_slow_ptrs(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow != nullptr && fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr)
                return nullptr;
            fast = fast->next;
            if (slow == fast) {
                ListNode *cur = head;
                while (cur != fast) {
                    cur = cur->next;
                    fast = fast->next;
                }
                return cur;
            }
        }
        return nullptr;
    }
};
