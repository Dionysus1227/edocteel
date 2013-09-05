class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        vector<int> expand;
        for (int i = 0; i < s.size(); i++) {
            expand.push_back(-1);
            expand.push_back(s[i]);
        }
        expand.push_back(-1);
        vector<int> best(expand.size(), 0);        
        int center = 1;        
        int ans = 1;
        for (int i = 1; i < expand.size(); i++) {            
            best[i]  = min(best[center * 2 - i], center + best[center] - i);
            for (; i - best[i] - 1 >= 0 && i + best[i] + 1 < expand.size()
                && expand[i - best[i] - 1] == expand[i + best[i] + 1]; best[i]++);
            if (i + best[i] > center + best[center])
                center = i;
            if (best[i] > best[ans])
                ans = i;            
        }
        return s.substr((ans - best[ans]) / 2, best[ans]);
    }
};
