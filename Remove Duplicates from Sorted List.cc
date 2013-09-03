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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = head;
        for (head = dummy; head != NULL; head = head->next)
            while (head->next != NULL && head->next->val == head->val)
                head->next = head->next->next;
        return dummy;        
    }
};