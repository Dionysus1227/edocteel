class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> cur;
        DFS(S, 0, cur, ans);
        return ans;   
    }
private:
    void DFS(const vector<int> &S, int index, vector<int> &cur, vector<vector<int> > &ans) {
        ans.push_back(cur);
        for (; index < S.size(); index++) {
             cur.push_back(S[index]);
             DFS(S, index + 1, cur, ans);
             cur.pop_back();
        }
    }    
};