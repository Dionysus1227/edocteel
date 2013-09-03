class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int ans = 0;
        int n = s.size();
        vector<int> f(s.size() + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {            
            if ('1' <= s[i] && s[i] <= '9') f[i + 1] += f[i];
            if (i > 0 && '1' <= s[i - 1] && s[i - 1] <= '2' && '0' <= s[i] && s[i] <= '9') {
                int val = (s[i - 1] - '0') * 10 + s[i] - '0';                
                if (10 <= val && val <= 26) f[i + 1] += f[i - 1];
            }
        }        
        return f[n];
    }
};