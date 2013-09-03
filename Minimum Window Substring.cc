class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> hash(256);
        vector<int> cnt(256);
        for (char ch : T)
            hash[ch]++;
        int head = 0;
        int len = 0;
        string ans;
        int min_len = INT_MAX;
        for (int tail = 0; tail <S.size(); tail++) {
            cnt[S[tail]]++;
            if (cnt[S[tail]] <= hash[S[tail]])
                len++;
            if (len == T.size()) {
                for (; head <=tail && cnt[S[head]] > hash[S[head]]; head++)
                    cnt[S[head]]--;
                if (tail - head + 1 < min_len) {
                    min_len = tail - head + 1;
                    ans = S.substr(head, tail - head + 1);
                }
            }
        }
        return ans;        
    }
};