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
    int maxPathSum(TreeNode *root) {
        int max_sum = 0;
        return MaxPathSum(root, max_sum);        
    }
private:
    int MaxPathSum(const TreeNode *root, int &max_sum) {
        if (root == NULL) return 0x80000000;
        int left = 0, right = 0;
        int ans = max(MaxPathSum(root->left, left), MaxPathSum(root->right, right));
        max_sum = max(0, root->val + max(left, right));
        return max(ans, root->val + left + right);
    }
};