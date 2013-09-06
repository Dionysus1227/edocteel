class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;
        string cur;
        Search(cur, 0, 0, n, ans);
        return ans;
    }
private:
    void Search(string &cur, const int left, const int right, const int n, vector<string> &ans) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (left > right) {
            cur += ")";
            Search(cur, left, right + 1, n, ans);
            cur.pop_back();
        }
        if (left < n) {
            cur += "(";
            Search(cur, left + 1, right, n, ans);
            cur.pop_back();            
        }
    }
};