 class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 0 || m == 0) return;
        bool first_row = false;
        for (int j = 0; j < m; j++)
            if (matrix[0][j] == 0) first_row = true;
        for (int i = 1; i < n; i ++) {
            bool zero = false;
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    zero = true;
                    matrix[0][j] = 0;                            
                }
            if (zero) 
                matrix[i].assign(m, 0);
        }
        for (int j = 0; j < m; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
        if (first_row)
            matrix[0].assign(m, 0);        
    }
};