class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s1.empty())
            return s2 == s3;
        if (s2.empty())
            return s1 == s3;
        vector< vector<bool> > f(s1.size() + 1, vector<bool>(s2.size() + 1, false));        
        for (int i = 0; i <= s1.size(); i++)
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) f[i][j] = true;
                else if (i == 0) 
                    f[i][j] = s2[j- 1] == s3[j - 1] && f[i][j - 1];
                else if (j == 0)
                    f[i][j] = s1[i - 1] == s3[i - 1] && f[i - 1][j];
                else f[i][j] = s1[i - 1] == s3[i + j - 1] && f[i - 1][j] ||
                    s2[j - 1] == s3[i + j - 1] && f[i][j - 1];
            }
        return f[s1.size()][s2.size()];
    }
};