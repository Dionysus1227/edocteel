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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int cur = 0;
        SumNum(root, cur, sum);
        return sum;
    }
private:
    void SumNum(const TreeNode *root, int cur, int &sum) {
        if (root == NULL) return;
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += cur;
            return;
        }
        SumNum(root->left, cur, sum);
        SumNum(root->right, cur, sum);
    }
};