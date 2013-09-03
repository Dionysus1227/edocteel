 class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> one(m, 0);
        vector<int> left(m, 0);
        vector<int> right(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') one[j] = 0;
                else one[j]++;
                left[j] = j - 1;
                for (; left[j] != -1 && one[left[j]] >= one[j]; left[j] = left[left[j]]);
            }
            for (int j = m - 1; j >= 0; j--) {
                right[j] = j + 1;
                for (; right[j] != m && one[right[j]] >= one[j]; right[j] = right[right[j]]);
                ans = one[j] * (right[j] - left[j] - 1);
            }                        
        }
        return ans;        
    }
};