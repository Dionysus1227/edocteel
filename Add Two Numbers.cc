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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry > 0) {
            ListNode *cur = new ListNode(carry);
            if (l1 != NULL) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            carry = cur->val / 10;
            cur->val %= 10;
            tail->next = cur;
            tail = cur;
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};