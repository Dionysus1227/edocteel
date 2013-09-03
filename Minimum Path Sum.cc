class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                grid[i][j] += min(i == 0 ? INT_MAX : grid[i - 1][j], 
                    j == 0 ? INT_MAX : grid[i][j - 1]);
            }
        return grid[n - 1][m - 1];
        
    }
};