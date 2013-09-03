class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> cur;
        vector<vector<int> > ans;
        DFS(n, k, 0, cur, ans);
        return ans;        
    }
private:
    void DFS(const int n, const int k, const int pre, vector<int> &cur, vector< vector<int> > &ans) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }        
        for (int val = pre + 1; val <= n - k + 1 + cur.size(); val++) {
            cur.push_back(val);
            DFS(n, k, val, cur, ans);
            cur.pop_back();
        }
    }
};