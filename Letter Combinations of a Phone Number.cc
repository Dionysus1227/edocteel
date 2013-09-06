class Solution {
public:
    vector<string> letterCombinations(string digits) {        
        vector<string> ans;
        string cur;
        Search(digits, cur, ans);
        return ans;
    }
private:
    const vector<string> dict = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void Search(const string &digits, string &cur, vector<string> &ans) {
        if (cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (char ch : dict[digits[cur.size()] - '0']) {
            cur.push_back(ch);
            Search(digits, cur, ans);
            cur.pop_back();
        }
    }
};