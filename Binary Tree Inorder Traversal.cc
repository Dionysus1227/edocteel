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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        while (root != NULL) {
            if (root->left == NULL) {
                ans.push_back(root->val);
                root = root->right;
                continue;
            }
            TreeNode *left = root->left;
            for (; left->right != NULL && left->right != root; left = left->right);
            if (left->right == root) {
                left->right = NULL;
                ans.push_back(root->val);
                root = root->right;
                continue;
            }
            left->right = root;
            root = root->left;
        }
        return ans;
    }
};