class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> hash(256, 0);
        int head = 0;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
            for (; head < i && hash[s[i]] > 1; head++)
                hash[s[head]]--;
            ans = max(ans, i - head + 1);
        }
        return ans;        
    }
};