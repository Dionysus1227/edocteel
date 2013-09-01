/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        for (ListNode *cur = head; cur != NULL; cur = cur->next, len++);
        return BuildBST(head, len);        
    }
private:    
    TreeNode *BuildBST(ListNode *&head, int len) {
        if (len <= 0) return NULL;
        TreeNode * cur = new TreeNode(0);
        cur->left = BuildBST(head, len >> 1);
        if (head != NULL) {
            cur->val = head->val;
            head = head->next;    
        }        
        cur->right = BuildBST(head, len - 1 - (len >> 1));
        return cur;
    }
};
