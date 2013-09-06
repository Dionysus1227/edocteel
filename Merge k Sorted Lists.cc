/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Cmp{
    bool operator() (ListNode *lhs, ListNode *rhs) const {
        return lhs->val > rhs->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (ListNode * & head : lists) {
            if (head != NULL) pq.push(head);
        }      
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            tail->next = top;
            tail = top;
            if (top->next != NULL) pq.push(top->next);
        }
        tail = dummy->next;
        delete dummy;
        return tail;
    }
private:

};