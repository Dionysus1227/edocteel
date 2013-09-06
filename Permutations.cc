class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<bool> vst(num.size(), false);
        vector<vector<int>> ans;
        vector<int> cur;
        Search(num, vst, cur, ans);
        return ans;
    }
private:
    void Search(const vector<int> &num, vector<bool> &vst, vector<int> &cur, vector<vector<int>> &ans) {
        if (cur.size() == num.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (vst[i] || i > 0 && num[i] == num[i - 1] && !vst[i - 1]) continue;
            vst[i] = true;
            cur.push_back(num[i]);
            Search(num, vst, cur, ans);
            cur.pop_back();
            vst[i] = false;
        }
    }    
};