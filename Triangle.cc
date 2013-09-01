class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < triangle[i].size() - 1; j++)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            triangle[i].back() += triangle[i - 1].back();
        }
        int ans = 0x7fffffff;
        for (int val : triangle.back())
            ans = min(ans, val);
        return ans;
    }
};
