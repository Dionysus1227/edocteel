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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return TestBalance(root, depth);        
    }
private:
    bool TestBalance(const TreeNode *root, int &depth) {
        if (root == NULL) return true;
        int left_depth = 0, right_depth = 0;
        if (!TestBalance(root->left, left_depth) || 
            !TestBalance(root->right, right_depth))
            return false;
        depth = max(left_depth, right_depth) +1;
        return abs(left_depth - right_depth) <= 1;
    }
};