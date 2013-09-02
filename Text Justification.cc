class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        vector<string> cur;
        int len = -1;
        for (string &word : words) {
            if (len + word.size() + 1 > L) {
                ans.push_back(GenerateLine(cur, L, false));
                cur.clear();
                len = -1;
            }            
            cur.push_back(word);
            len += word.size() + 1;
        }
        ans.push_back(GenerateLine(cur, L, true));
        return ans;
    }
private:    
    string GenerateLine(const vector<string> &cur, const int L, bool is_last) {        
        string line(L, ' ');
        if (cur.size() == 1) {            
            line.replace(0, cur.front().size(), cur.front());
            return line;
        }
        int word_len = 0;
        for (const string &word : cur)
            word_len += word.size();
        int split = (L - word_len) / (cur.size() - 1);
        int mod  = (L - word_len) % (cur.size() - 1);
        int i = 0;
        for (const string &word : cur) {
            line.replace(i, word.size(), word);
            i += word.size();
            if (is_last) {
                i++;
            }else {
                i += split;
                if (mod > 0) {                
                mod--;
                i++;
            }
            }
        }
        return line;
    }
    
};