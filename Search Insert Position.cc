class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target <= A[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return l;        
    }
};