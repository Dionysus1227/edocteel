class Solution {
public:
    int largestRectangleArea(vector<int> &height) {                
        int m = height.size();        
        vector<int> left(m, 0);
        vector<int> right(m, 0);
        int ans = 0;        
        for (int j = 0; j < m; j++) {
            left[j] = j - 1;
            for (; left[j] != -1 && height[left[j]] >= height[j]; left[j] = left[left[j]]);
        }
        for (int j = m - 1; j >= 0; j--) {
            right[j] = j + 1;
            for (; right[j] != m && height[right[j]] >= height[j]; right[j] = right[right[j]]);
            ans = max(ans, height[j] * (right[j] - left[j]- 1));
        }                                
        return ans;        
        
    }
};