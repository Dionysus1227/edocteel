class Solution {
public:
    int atoi(const char *str) {
        string s(str);
        if (s.find_first_not_of(' ') == string::npos)
            return 0;
        s = s.substr(s.find_first_not_of(' '));
        if (s.empty()) return 0;
        bool sign = true;        
        if (s[0] == '+' || s[0] == '-') {
            sign = s[0] == '+';
            s = s.substr(1);            
        }
        int val = 0;
        for (int i = 0; i < s.size() && '0' <= s[i] && s[i] <= '9'; i++) {
            int cur = s[i] - '0';
            if (sign) {
                if (val > (INT_MAX - cur) / 10)
                    return INT_MAX;
                val = val * 10 + cur;
            } else {
                if (val < (INT_MIN + cur) / 10)
                    return INT_MIN;
                val = val * 10 - cur;
            }            
        }
        return val;
    }
};