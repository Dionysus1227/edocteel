class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> f(3, 0);
        f[2] = 1;
        for (int i = 0; i < s.size(); i++) {
            f[i % 3] = 0;
            if ('1' <= s[i] && s[i] <='9') f[i % 3] += f[(i + 2) % 3];
            if (i > 0 && '1' <= s[i - 1] && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
                f[i % 3] += f[(i + 1) % 3];
        }
        return f[(s.size() - 1) % 3];
    }
};
