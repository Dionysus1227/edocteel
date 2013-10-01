class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0) return 0;
        int n = ratings.size();
        vector<int> candys(n, 0);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || ratings[i - 1] >= ratings[i]) cur = 1;
            else cur++;
            candys[i] = max(candys[i], cur);
        }
        cur = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || ratings[i + 1] >= ratings[i]) cur = 1;
            else cur++;
            candys[i] = max(candys[i], cur);
        }
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += candys[i];
        return tot;
    }
};
