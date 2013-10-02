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

//Solution with constant space
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0) return 0;
        int n = ratings.size();
        int tot = 0;
        int pre_value = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || ratings[i - 1] < ratings[i]) {
                ++cur;
                if (i + 1 == n || ratings[i] <= ratings[i + 1])
                    tot += cur;
                else pre_value = cur;
            } else if (i + 1 == n || ratings[i] <= ratings[i + 1]) {
                int j = i;
                for (cur = 1; j > 0 && ratings[j - 1] > ratings[j]; j--, cur++)
                    tot += cur;
                if (j > 0 && ratings[j - 1] < ratings[j]) cur = max(cur, pre_value);
                tot += cur;
                pre_value = 1;
                cur = 1;
            }
        }
        return tot;
    }
};
