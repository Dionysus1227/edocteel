class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string ,int> cnt;
        for (string &word : L) cnt[word]++;            
        vector<int> ans;
        if (L.empty() || L[0].empty() || S.empty()) return ans;
        int len = L[0].size();
        for (int start = 0; start < len; start++) {
            unordered_map<string, int> cur;
            int match = 0;
            for (int i = start; i + len <= S.size(); i+= len) {                
                int pre = i - L.size() * len;
                if (pre >= start) {
                    string head = S.substr(pre, len);
                    if (cnt.find(head) != cnt.end()) {
                        cur[head]--;
                        if (cur[head] < cnt[head]) match--;
                    }
                }
                string word = S.substr(i, len);
                if (cnt.find(word) != cnt.end()) {
                    cur[word]++;
                    if (cur[word] <= cnt[word]) match++;
                }
                if (match == L.size()) ans.push_back(pre + len);
            }
        }
        return ans;
    }
};
