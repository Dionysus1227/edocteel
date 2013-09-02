class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) & 1)
            return FindKth(A, m, B, n, (m + n) >> 1);
        else return (FindKth(A, m, B, n, (m + n) >> 1) + FindKth(A, m, B, n, ((m + n) >> 1) - 1)) / 2.0;        
    }
private:
    int FindKth(int A[], int m, int B[], int n, int k) {
        int l = 0, r = min(m - 1, k);
        while (l <= r) {
            int mid = l + (r - l >> 1);
            int mirror = k - 1 - mid;
            if (mirror < -1) r = mid - 1;                
            else if (mirror + 1 == 0 || mirror < n && A[mid] >= B[mirror]) {
                if (mirror + 1 == n || A[mid] <= B[mirror + 1])
                    return A[mid];
                else r = mid - 1;
            } else l = mid + 1;
        }
        return FindKth(B, n, A, m, k);
    }
};
