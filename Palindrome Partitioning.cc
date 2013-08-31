class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        int n = s.size();        
        if (n == 0) return ans;
        vector<vector<bool> > is_pali(n, vector<bool>(n, false));
        CalculateIsPali(s, is_pali);
        vector<string> cur;
        search(s, is_pali, 0, cur, ans);
        return ans;
    }
private:
    void search(const string &s, const vector<vector<bool> > &is_pali, int len,
        vector<string> &cur, vector<vector<string> > &ans) {
            if (len == s.size()) {
                ans.push_back(cur);
                return;
            }
            for (int i = len; i < s.size(); i++) {
                if (!is_pali[len][i]) continue;
                cur.push_back(s.substr(len, i - len + 1));
                search(s, is_pali, i + 1, cur, ans);
                cur.pop_back();
            }
        }

    void CalculateIsPali(const string &s, vector<vector<bool> > &is_pali) {
        for (int len = 0; len < s.size(); len++) {
            for (int i = 0; i + len < s.size(); i++) {
                int j = i + len;
                is_pali[i][j] = s[i] == s[j];
                if (len > 1)
                    is_pali[i][j] = is_pali[i][j] & is_pali[i + 1][j - 1];
            }            
        }
    }    
};