class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        string ans;
        int chunk = nRows * 2 - 2;
        for (int k = 0; k < nRows; k++) {
            for (int i = k; i < s.size();  i += chunk) {                
                ans.push_back(s[i]);
                if (0 < k  && k < nRows - 1 && i + chunk - k * 2 < s.size())
                    ans.push_back(s[i + chunk - k * 2]);
            }
        }
        return ans;
    }
};