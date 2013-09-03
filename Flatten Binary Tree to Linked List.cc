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
    void flatten(TreeNode *root) {
        TreeNode *head = NULL;
        TreeNode *tail = NULL;
        Flatten(root, head, tail);        
    }
private:
    void Flatten(TreeNode *root, TreeNode *&head, TreeNode *&tail) {
        head = tail = root;
        if (root == NULL) return;
        TreeNode *left_head = NULL;
        TreeNode *left_tail = NULL;
        TreeNode *right_head = NULL;
        TreeNode *right_tail = NULL;
        
        Flatten(root->left, left_head, left_tail);        
        Flatten(root->right, right_head, right_tail);
        root->left = NULL;
        Connect(head, tail, left_head, left_tail);                
        Connect(head, tail, right_head, right_tail);        
    }
    void Connect(TreeNode *&head, TreeNode *&tail, TreeNode *child_head, TreeNode *child_tail) {
        if (child_head == NULL) return;
        tail->right = child_head;
        tail = child_tail;
    }
};