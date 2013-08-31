class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> second(n, 0);
        int forward = prices[n - 1];
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            second[i] = max(second[i + 1], forward - prices[i]);
            forward = max(forward, prices[i]);
            ans = max(ans, second[i]);
        }
        return ans;
    }
};
