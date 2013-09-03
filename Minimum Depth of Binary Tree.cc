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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        return min((root->left == NULL ? INT_MAX : 1 + minDepth(root->left)), 
            (root->right == NULL ? INT_MAX : 1 + minDepth(root->right)));    
    }
};