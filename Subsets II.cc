class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> cur;
        DFS(S, 0, cur, ans);
        return ans;   
    }
private:
    void DFS(const vector<int> &S, int index, vector<int> &cur, vector<vector<int> > &ans) {
        ans.push_back(cur);
        while (index < S.size()) {
            int next = index + 1;
            for (; next < S.size() && S[next] == S[index]; next++);
            for (int i = index; i < next; i++) {
                cur.push_back(S[i]);
                DFS(S, next, cur, ans);
            }
            for (int i = index; i < next; i++)
                cur.pop_back();
            index = next;        
        }        
    }
};