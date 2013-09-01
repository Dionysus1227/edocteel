class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) return false;        
        int left = 0, right = n - 1;
        for (; left <= right && A[left] == A[right]; left++);
        if (left == n) return A[0] == target;        
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target) return true;
            if (A[mid] > A[n - 1]) {
                if (A[left] <= target && target < A[mid])
                    right = mid - 1;
                else left = mid + 1;
            } else if (A[mid] < target && target <= A[n - 1])
                        left = mid + 1;
                    else right = mid - 1;    
        }
        return false;        
    }
};