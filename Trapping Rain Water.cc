class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        int highest = 0;
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (A[i] > highest) {
                highest = A[i];
                pos = i;
            }
        }
        int ans = 0;
        int pre = 0;        
        for (int i = 0; i < pos; i++) {
            ans += max(0, pre - A[i]);
            pre = max(pre, A[i]);
        }
        pre = 0;
        for (int i = n - 1; i > pos; i--) {
            ans += max(0, pre - A[i]);
            pre = max(pre, A[i]);
            
        }
        return ans;        
    }
};