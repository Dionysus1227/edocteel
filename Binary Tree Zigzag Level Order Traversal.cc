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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector< vector<int> > nodes;        
        DFS(root, 0, nodes);
        for (int i = 0; i < nodes.size(); i++)
            if (i&1) reverse(nodes[i].begin(), nodes[i].end());
        return nodes;  
        
    }
private:
    void DFS(const TreeNode * root, int depth, vector<vector<int> > &nodes) {
        if (root == NULL) return;
        while (depth >= nodes.size())
            nodes.push_back(vector<int>());
        nodes[depth].push_back(root->val);
        DFS(root->left, depth + 1, nodes);
        DFS(root->right, depth + 1, nodes);
    }            
};