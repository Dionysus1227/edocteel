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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * second = dummy;
        for (int i = 0; i < n; i++) {
            second = second->next;
            if (second == NULL) {
                delete dummy;
                return head;
            }
        }
        head = dummy;
        for (;second->next != NULL; head = head->next, second = second->next);
        head->next = head->next->next;
        head = dummy->next;
        delete dummy;
        return head;
        
    }
};
