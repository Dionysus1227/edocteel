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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (l1 != NULL || l2 != NULL) {
            if (l2 == NULL || l1 != NULL && l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }            
        }
        tail->next = NULL;
        tail = dummy->next;
        delete dummy;
        return tail;        
    }
};