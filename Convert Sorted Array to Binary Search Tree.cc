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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return BuildBST(num, 0, num.size() - 1);        
    }
private:
    TreeNode *BuildBST(const vector<int> &num, const int left, const int right) {
        if (left > right) return NULL;
        int mid = left + (right - left >> 1);
        TreeNode *root = new TreeNode(num[mid]);
        root->left = BuildBST(num, left, mid - 1);
        root->right = BuildBST(num, mid + 1, right);
        return root;
    }
};