class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!f[i]) continue;
            for (string word : dict) {
                if (i + word.size() > s.size()) continue;
                if (s.substr(i, word.size()) == word)
                    f[i + word.size()] = true;
            }
        }
        return f[s.size()];
    }
};
