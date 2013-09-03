class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        m--;n--;
        for (int i = m + n + 1; i >= 0; i--) {
            if (n < 0 || m >= 0 && A[m] > B[n])
                A[i] = A[m--];
            else A[i] = B[n--];                
        }        
    }
};