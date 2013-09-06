class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {        
        string ans = "";
        if (strs.size() == 0) return ans;
        for (int i = 0; i < strs[0].size(); i++) {
            int j = 0;
            for (j; j < strs.size(); j++)
                if (i == strs[j].size() || strs[0][i] != strs[j][i]) break;
            if (j < strs.size()) break;
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};