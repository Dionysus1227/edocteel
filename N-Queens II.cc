class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        DFS((1<<n) - 1, 0, 0, ans);
        return ans;
    }
private:
    void DFS(const int candicate, const int left, const int right, int &ans) {        
        if (!candicate) {
            ans++;
            return;
        }
        int cur = 0;
        int can = candicate & ~(left | right);
        while (can) {
            cur = can & -can;
            if (!(cur & left) && !(cur & right))
                DFS(candicate ^ cur, (left | cur) << 1, (right | cur) >> 1, ans);
            can = can & (can - 1);
        }        
    }
};