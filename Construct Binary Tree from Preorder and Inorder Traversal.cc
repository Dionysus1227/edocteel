/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef vector<int>::const_iterator Iter;
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return Build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());        
    }
private:
    TreeNode *Build(const Iter pre_begin, const Iter pre_end, const Iter in_begin, const Iter in_end) {
        if (pre_begin == pre_end) return NULL;
        TreeNode *root = new TreeNode(*pre_begin);
        Iter split = find(in_begin, in_end, *pre_begin);
        int left_len = split - in_begin;
        root->left = Build(pre_begin + 1, pre_begin + 1 + left_len, in_begin, split);
        root->right = Build(pre_begin + 1 + left_len, pre_end, split + 1, in_end);
        return root;
    }
};