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
        auto cmp = [] (ListNode* left, ListNode* right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pqueue(cmp);
        ListNode * head = new ListNode(-1), *tail = head;
        for (ListNode* list : lists) {
            if (list) {
                pqueue.push(list);
            }
        }
        while (!pqueue.empty()) {
            auto cur = pqueue.top();
            pqueue.pop();
            if (cur->next) {
                pqueue.push(cur->next);
            }
            tail->next = cur;
            tail = tail->next;
            cur->next = nullptr;
        }
        return head->next;
    }
};
