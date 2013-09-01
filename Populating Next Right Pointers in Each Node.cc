/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *next_head = NULL;
        TreeLinkNode *pre = NULL;
        for (root; root != NULL; root = root->next) {
            Update(pre, root->left, next_head);
            Update(pre, root->right, next_head);
        }
        connect(next_head);        
    }
private:
    void Update(TreeLinkNode *&pre, TreeLinkNode *&cur, TreeLinkNode *&head) {
        if (cur == NULL) return;
        if (head == NULL) {
            pre = head = cur;
            return;
        }
        pre->next = cur;
        pre = cur;
    }
};