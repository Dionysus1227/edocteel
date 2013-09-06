class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s);   
        int m = strlen(p);
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) f[i][j] = true;
                else if (j == 0) f[i][j] = false;
                else if (i== 0) f[i][j] = j % 2 == 0 && p[j - 1] == '*' && f[i][j - 2];
                else f[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && f[i - 1][j - 1] ||
                        p[j - 1] == '*' && (f[i][j - 2] || f[i - 1][j] &&
                            (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
            }
        return f[n][m];
    }
};
