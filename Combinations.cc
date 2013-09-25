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
//non-recursion version
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        int i = 0;
        vector<int> cur(k, 0);
        while (i >= 0) {
            if (i == k) {
                ans.push_back(cur);
                i--;
                continue;
            }
            if (cur[i] == 0) {
                if (i == 0) cur[i] = 1;
                else cur[i] = cur[i - 1] + 1;
            } else cur[i]++;
            if (cur[i] > n) {
                cur[i--] = 0;
            } else i++;
        }
        return ans;
    }
};
