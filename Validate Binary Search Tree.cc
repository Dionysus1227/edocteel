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
    bool isValidBST(TreeNode *root) {
        int min_val, max_val;
        return IsValid(root, min_val, max_val);        
    }
private:
    bool IsValid(const TreeNode *root, int &min_val, int &max_val) {
        if (root == NULL) return true;
        min_val = max_val = root->val;
        int left_min, left_max, right_min, right_max;
        if (!IsValid(root->left, left_min, left_max) || !IsValid(root->right, right_min, right_max))
            return false;
        if (root->left != NULL) {
            if (left_max >= root->val) return false;
            min_val = left_min;
        }        
        if (root->right != NULL){
            if (right_min <= root->val) return false;
            max_val = right_max;
        }
        return true;
    }
};