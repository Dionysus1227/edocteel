class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) return true;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            if (max_len < i) return false;
            max_len = max(max_len, i + A[i]);
        }
        return true;        
    }
};