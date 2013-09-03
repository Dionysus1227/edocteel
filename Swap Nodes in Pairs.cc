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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        for (; head->next != NULL && head->next->next != NULL; head = head->next->next) {
            ListNode *first = head->next;
            ListNode *second = head->next->next;
            first->next = second->next;
            second->next = first;
            head->next = second;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
