class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0) return -1;
        vector<int> best(n);
        int pre = 0;        
        for (int i = 1; i < n; i++) {
            for (; pre < i && pre + A[pre] < i; pre++);
            if (pre == i) return -1;
            best[i] = best[pre] + 1;            
        }
        return best[n - 1];
    }
};