 class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left >> 1);
            int cur = matrix[mid / m][mid % m];
            if (cur == target) return true;
            else if (target < cur) right = mid - 1;
                else left = mid + 1;
        }
        return false;
    }
};