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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        FindPath(root, sum, cur, ans);
        return ans;
    }
    
    void FindPath(const TreeNode *root, int sum, vector<int> &cur, vector<vector<int> > &ans) {
        if (root == NULL) {
            return;
        }
        cur.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            ans.push_back(cur);
        } 
        FindPath(root->left, sum, cur, ans);
        FindPath(root->right, sum, cur, ans);
        cur.pop_back();
    }
};
