class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        vector<int> f(n + 1);
        f[0] = f[1] = 1;        
        for (int i = 2; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2];
        return f[n];        
    }
};