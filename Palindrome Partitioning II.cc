class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        vector<vector<bool> > is_pali(n, vector<bool>(n, false));
        CalculateIsPali(s, is_pali);
        vector<int> best(n, n);
        best[0] = 0;
        for (int i = 1; i < n; i++) {
            if (is_pali[0][i]) {
                best[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (is_pali[j + 1][i])
                    best[i] = min(best[i], best[j] + 1);
            }
        }
        return best[n - 1];        
    }
private:
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