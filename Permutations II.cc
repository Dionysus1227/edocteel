class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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
//non-recursion version
class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        int n = num.size();
        vector<bool> vst(n + 1, false);
        vector<vector<int> > ans;
        int i = 0;
        vector<int> cur(n, -1);
        while (i >= 0) {
            if (i == n) {
                vector<int> permutation;
                for (int index : cur) {
                    permutation.push_back(num[index]);
                }
                ans.push_back(permutation);
                i--;
                continue;
            }
            if (cur[i] >= 0) vst[cur[i]] = false;
            for (++cur[i]; cur[i] < n && (vst[cur[i]] || cur[i] > 0 && num[cur[i]] == num[cur[i] - 1] && !vst[cur[i] - 1]); ++cur[i]);
            if (cur[i] == n) {
                cur[i--] = -1;
            } else vst[cur[i++]] = true;
        }
        return ans;
    }
};
