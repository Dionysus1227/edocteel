class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            for (; i < j && !IsLegal(s[i]); i++);
            for (; i < j && !IsLegal(s[j]); j--);
            if (i >= j) break;
            if ((s[i] >= 'a' ? s[i] - 32 : s[i]) != 
                (s[j] >= 'a' ? s[j] - 32 : s[j])) return false;
        }
        return true;
    }
private:
    bool IsLegal(char ch) const {
        return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' ||
            '0' <= ch && ch <= '9';
    }
};
