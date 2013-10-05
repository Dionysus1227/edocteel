/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next->next) {
            RandomListNode *copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
        }
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next->next)
            if (cur->random != NULL) cur->next->random = cur->random->next;
        RandomListNode *copy_head = head->next;
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next) {
            RandomListNode *next = cur->next->next;
            if (next != NULL) cur->next->next = next->next;
            cur->next = next;
        }
        return copy_head;
    }
};
