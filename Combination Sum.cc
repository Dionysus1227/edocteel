class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector<int> > pre(target + 1);
        pre[0].push_back(0);
        sort(candidates.rbegin(), candidates.rend());
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = 0; j + candidates[i] <= target; j++)
                if (pre[j].size() > 0)
                    pre[j + candidates[i]].push_back(j);
        }
        vector<vector<int> > ans;
        vector<int> cur;
        DFS(target, pre, cur, ans);
        return ans;
    }
private:
    void DFS(const int target, const vector<vector<int> > &pre, 
        vector<int> &cur, vector<vector<int> > &ans) {
            if (target == 0) {
                ans.push_back(cur);
                return;
            }
            for (int parent : pre[target]) {
                if (cur.size() > 0 && cur.back() > target - parent)
                    continue;
                cur.push_back(target - parent);
                DFS(parent, pre, cur, ans);
                cur.pop_back();
            }
        }
};
