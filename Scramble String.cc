class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;
        int n = s1.size();
        vector< vector< vector<int> > > f(n + 1, vector< vector<int> >(n + 1, vector<int>(n + 1, -1)));
        return Search(0, 0, n, f, s1, s2) == 1;
    }
private:
    bool Search(int i, int j, int len, vector< vector< vector<int> > > &f, 
        const string &s1, const string &s2) {
        if (f[i][j][len] >= 0) return f[i][j][len] == 1;
        if (len == 1) 
            return (f[i][j][len] = (s1[i] == s2[j] ? 1 : 0)) == 1;
        f[i][j][len] = 0;
        for (int cut = 1; cut < len; cut++)
            if (Search(i, j, cut, f, s1, s2) && Search(i + cut, j + cut, len - cut, f, s1, s2) ||
                Search(i, j + len - cut, cut, f, s1, s2) && Search(i + cut, j, len - cut, f, s1, s2)) {
                    f[i][j][len] = 1;
                    break;
                }
        return f[i][j][len] == 1;
    }
};