/*
Merge k sorted linked lists and return it as one sorted list. Analyze and
describe its complexity.

Example:
Input: [ 1->4->5,    1->3->4,    2->6 ]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [] (ListNode*& n1, ListNode*& n2) {
            return n1->val > n2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode dummy, *tail = &dummy;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur->next) {
                pq.push(cur->next);
            }
            tail->next = cur;
            tail = tail->next;
        }
        return dummy.next;
    }
};
