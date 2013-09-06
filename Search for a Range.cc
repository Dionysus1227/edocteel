class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target <= A[mid]) r = mid - 1;
            else l = mid + 1;
        }
        if (A[l] != target) return {-1, -1};
        ans.push_back(l);
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target < A[mid]) r = mid - 1;
            else l = mid + 1;
        }
        ans.push_back(r);
        return ans;
    }
};