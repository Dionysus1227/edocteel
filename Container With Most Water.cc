class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) return 0;
        int left = 0, right = height.size() - 1;
        int ans = INT_MAX;
        while (left < right) {
            ans = max(ans, min(height[right], height[left]) * (right - left));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};