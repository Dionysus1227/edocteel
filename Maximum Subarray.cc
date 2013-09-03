class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;
        int s = 0;
        int ans = A[0];
        for (int i = 0; i < n; i ++) {
            if (s < 0) s = 0;
            s += A[i];
            ans = max(ans, s);
        }
        return ans;
    }
};
