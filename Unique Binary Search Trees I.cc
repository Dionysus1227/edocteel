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
    vector<TreeNode *> generateTrees(int n) {
        return GenerateTrees(1, n);        
    }
private:
    vector<TreeNode *> GenerateTrees(int from, int to) {
        vector<TreeNode *> ans;
        if (from > to) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = from; i <= to; i++) {
            vector<TreeNode *> left = GenerateTrees(from, i - 1);
            vector<TreeNode *> right = GenerateTrees(i + 1, to);
            for (TreeNode* left_child : left)
                for (TreeNode* right_child : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_child;
                    root->right = right_child;
                    ans.push_back(root);
                }
        }
        return ans;
    }
};