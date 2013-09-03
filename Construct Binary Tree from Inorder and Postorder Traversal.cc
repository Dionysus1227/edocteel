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

typedef vector<int>::const_iterator Iter;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return BuildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode *BuildTree(const Iter inorder_begin, const Iter inorder_end, 
            const Iter postorder_begin, const Iter postorder_end) {
        if (postorder_begin >= postorder_end) return NULL;
        const Iter root_it = postorder_end - 1;
        TreeNode * root = new TreeNode(*root_it);
        const Iter split = find(inorder_begin, inorder_end, *root_it);
        size_t left_len = split - inorder_begin;
        root->left = BuildTree(inorder_begin, split,
            postorder_begin, postorder_begin + left_len);
        root->right = BuildTree(split + 1, inorder_end, 
            postorder_begin + left_len, root_it); 
        return root;
    }
};