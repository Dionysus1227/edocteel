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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return IsSame(root->left, root->right);
    }
private:
    bool IsSame(TreeNode *left, TreeNode *right) const {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return left->val == right->val &&
        IsSame(left->left, right->right) && IsSame(left->right, right->left);
    }
};