class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector< vector<int> > ans(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0;  j < n; j++)
                if (i <= j) {
                    int d = min(i, n - 1 - j);
                    ans[i][j] = 4 * (n - d) * d + (1 + i + j - d * 2);
                } else {
                    int d = min(j, n - 1 - i);
                    ans[i][j] = 4 * (n - d - 1) * (d + 1)  + (d * 2 + 1 - i - j);
                }
        return ans;
    }
};