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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        while (head != NULL) {
            ListNode *tail = head->next;
            if (tail == NULL) break;
            Reverse(head, k);
            head = tail;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
private:
    void Reverse(ListNode *head, int k) {        
        ListNode *tail = head;
        for (int i = 0; i <= k; i++, tail = tail->next)
            if (tail == NULL) return;
        tail = head->next;
        for (int i = 0; i < k - 1; i++) {
            ListNode *forward = tail->next;
            tail->next = forward->next;
            forward->next = head->next;
            head->next = forward;
        }
    }    
};
