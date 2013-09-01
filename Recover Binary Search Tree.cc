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
    void recoverTree(TreeNode *root) {
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *pre = NULL;
        while (root != NULL) {            
            if (root->left == NULL) {
                Update(root, pre, first, second);
                root = root->right;
                continue;
            }
            TreeNode *back = root->left;
            for (;back->right != NULL && back->right != root; back = back->right);
            if (back->right == root) {
                Update(root, pre, first, second);
                back->right = NULL;              
                root = root->right;
            } else {
                back->right = root;
                root = root->left;
            }            
        }
        if (first != NULL && second != NULL) {
            swap(first->val, second->val);    
        }        
    }
private:
    void Update(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second) {
        if (pre != NULL && root != NULL && pre->val > root->val) {
            if (first == NULL)
                first = pre;
            second = root;
        }
        pre = root;
    }
};