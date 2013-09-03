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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;
        int len = 1;
        ListNode *tail = head;
        for (; tail->next != NULL; tail = tail->next, len++);
        k = k % len;
        if (k == 0) return head;
        ListNode *new_tail = head;
        for (int i = 0 ; i < len - k - 1; i++)
            new_tail = new_tail->next;
        tail->next = head;
        head = new_tail->next;
        new_tail->next = NULL;
        return head;
    }
};