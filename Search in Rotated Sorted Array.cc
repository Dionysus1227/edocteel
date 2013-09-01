class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target) return mid;
            if (A[0] <= A[mid]) {
                if (A[0] <= target && target < A[mid])
                    right = mid - 1;
                else left = mid + 1;
            } else {
                if (A[mid] < target && target <= A[n - 1])
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
        
    }
};