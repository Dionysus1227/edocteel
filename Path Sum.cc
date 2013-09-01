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
    bool hasPathSum(TreeNode *root, int sum) {
        return FindPath(root, sum);        
    }
        
    bool FindPath(const TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            return true;
        } 
        return FindPath(root->left, sum) || FindPath(root->right, sum);
    
    }
};
