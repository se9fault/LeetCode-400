/*
Given a singly linked list where elements are sorted in ascending order, convert
it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in
which the depth of the two subtrees of  every  node never differ by more than 1.

Example:
Given the sorted linked list: -10 -> -3 -> 0 -> 5 -> 9,
One possible answer is: [0,-3,9,-10,null,5], which represents the following
height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5
*/

// Solution:
// recursion; also use fast/slow ptr to get middle element
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return head;
        return helper(head, nullptr);
    }
private:
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *cur = new TreeNode(slow->val);
        cur->left = helper(head, slow);
        cur->right = helper(slow->next, tail);
        return cur;
    }
};
