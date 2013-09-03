class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int i = 1; i <= min(3, (int)s.size() - 1); i++) {
            string ip0 = s.substr(0, i);
            if (!Legal(ip0)) continue;
            for (int j = i + 1; j <= min(i + 3, (int)s.size() - 1); j++) {
                string ip1 = s.substr(i, j - i);
                if (!Legal(ip1)) continue;
                for (int k = j + 1; k <= min(j + 3, (int)s.size() - 1); k++) {
                    string ip2 = s.substr(j, k - j);
                    string ip3 = s.substr(k);
                    if (!Legal(ip2) || !Legal(ip3)) continue;
                    ans.push_back(ip0 + "." + ip1 + "." + ip2 + "." + ip3);
                }
            }
        }            
        return ans;        
    }
private:
    bool Legal(const string &s) {
        if (s.empty() || s.size() > 3) return false;
        if (s[0] == '0')
            return s.size() == 1;
        int num = 0;
        for (char ch : s) {
            if (ch < '0' || ch > '9') return false;
            num = num * 10 + ch - '0';
        }
        return 0 <= num && num < 256;
    }
};