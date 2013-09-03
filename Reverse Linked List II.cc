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
    ListNode *reverseBetween(ListNode *head, int m, int n) {        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        ListNode *tail = dummy->next;
        for (int i = 0; i < n - 1; i++)
            if (i >= m - 1) {
                ListNode *node = tail->next;                
                tail->next = tail->next->next;
                node->next = head->next;
                head->next = node;
            } else {
                head = head->next;
                tail = tail->next;
            }
        head = dummy->next;
        delete dummy;
        return head;
    }
};