class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector< vector<int> > f(2, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (obstacleGrid[i][j]) f[i&1][j] = 0;
                else if (i == 0 && j == 0) f[i&1][j] = 1;
                    else if (i == 0) f[i][j] = f[i&1][j - 1];
                        else if (j == 0) f[i&1][j] = f[1 - (i&1)][j];
                            else f[i&1][j] = f[i&1][j - 1] + f[1 - (i&1)][j];
        return f[(m - 1)&1][n - 1];        
    }
};