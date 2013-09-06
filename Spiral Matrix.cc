class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int n = matrix.size();                 
        if (n == 0) return ans;
        int m = matrix[0].size();
        if (m == 0) return ans;
        for (int d = 0; d < min((m + 1) / 2, (n + 1) / 2); d++) {
            for (int j = d; j <= m - 1 - d; j++)
                ans.push_back(matrix[d][j]);                
            for (int i = d + 1; i <= n - 2 - d; i++)
                ans.push_back(matrix[i][m - 1 - d]);                
            if (d < n - 1 - d)
            for (int j = m - 1 - d; j >= d; j--)
                ans.push_back(matrix[n - 1 - d][j]);
            if (d < m - 1 - d)                            
            for (int i = n - 2 - d; i >= d + 1; i--)
                ans.push_back(matrix[i][d]);                
        }
        return ans;
    }    
};