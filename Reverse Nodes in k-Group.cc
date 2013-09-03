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
        if (k <= 1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        while (head != NULL) {
            ListNode *tail = head;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == NULL) break;
            }
            if (tail == NULL) break;
            ListNode *next_head = tail->next;
            ListNode *cur_tail = head->next;
            Reverse(head, tail);
            cur_tail->next = next_head;
            head = cur_tail;                
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
private:
    void Reverse(ListNode *head, ListNode *tail) {        
        ListNode *cur = head->next->next;
        while (true) {
            ListNode *next_cur = cur->next;            
            cur->next = head->next;
            head->next = cur;
            if (cur == tail) break;
            cur = next_cur;
        }    
    }
};
