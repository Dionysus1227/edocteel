class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.rbegin(), num.rend());
        vector< vector<int> > pre(target + 1);
        pre[0].push_back(0);
        for (int i = 0, j = 0; i < num.size(); i++)
            for (int j = target - num[i]; j >= 0; j--)
                if (!pre[j].empty())       
                    pre[j + num[i]].push_back(i);
        vector< vector<int> > ans;
        vector<int> cur;
        DFS(target, pre, num, cur, ans);
        return ans;
    }
private:
    void DFS(const int target, const vector< vector<int> > &pre, const vector<int> &num, 
            vector<int> &cur, vector< vector<int> > &ans) {
        if (target == 0) {
            vector<int> item;
            for (int index : cur)
                item.push_back(num[index]);
            ans.push_back(item);
            return;
        }
        int last = -1;
        for (int i = pre[target].size() - 1; i >=0; i--) {
    		int parent = pre[target][i];
            if (num[parent] != last && (cur.empty() || cur.back() > parent)) {
                cur.push_back(parent);
                DFS(target - num[parent], pre, num, cur, ans);
                cur.pop_back();
                last = num[parent];
            }            
        }    
    }
};
