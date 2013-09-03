class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector< vector<int> > f(n + 1, vector<int>(m + 1));         
        for (int i = 0; i <= n; i++)
         for (int j = 0; j <= m; j++)
             if (i == 0 && j == 0) f[i][j] = 0;
             else if (i == 0) f[i][j] = j;                
                else if (j == 0) f[i][j] = i;
                    else f[i][j] = min(
                        min(f[i - 1][j] + 1, f[i][j - 1] + 1), 
                        f[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 :1));         
        return f[n][m];            
    }
};