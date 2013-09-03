class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > f(2, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0) f[0][j] = 1;
                else if (j == 0) f[i&1][j] = 1;
                    else f[i&1][j] = f[i&1][j - 1] + f[1 - (i&1)][j];
        return f[(m - 1)&1][n - 1];
    }
};