class Solution {
public:
    int numDistinct(string S, string T) {
        if (T.size() == 0) return 0;        
        vector<vector<int> > num(2, vector<int>(S.size(), 0));
        int ans = 0;
        for (int i = 0; i < T.size(); i++) {
            num[1].assign(S.size(), 0);
            int pre = i == 0 ? 1 : 0;
            for (int j = 0; j < S.size(); j++) {
                if (S[j] == T[i])
                    num[1][j] = pre;
                pre += num[0][j];
                if (i == T.size() - 1) ans += num[1][j];
            }
            num[0] = num[1];
        }
        return ans;
    }
};