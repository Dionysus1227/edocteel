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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less = new ListNode(-1);
        ListNode *not_less = new ListNode(-1);
        ListNode *less_tail = less;
        ListNode *not_less_tail = not_less;
        for (;head != NULL; head = head->next) {                    
            if (head->val < x) {
                less_tail->next = head;
                less_tail = head;
            } else {
                not_less_tail->next = head;
                not_less_tail = head;
            }
        }
        less_tail->next = not_less->next;
        not_less_tail->next = NULL;
        head = less->next;
        delete less;
        delete not_less;
        return head;        
    }
};