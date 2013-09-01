class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i = 0, j = 0, k = n; j < k; j++) {
            if (A[j] == 2) {                
                for (--k; j < k && A[k] == 2; k--);
                if (j >= k) return;
                swap(A[j], A[k]);
            }
            if (A[j] == 0) 
                swap(A[j], A[i++]);            
        }        
    }
};