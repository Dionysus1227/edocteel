class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s);
        int m = strlen(p);
        int star = -1, pre = -1;
        int i = 0, j = 0;
        while (i < n) {
            if (p[j] == '*') {
                star = j++;
                pre = i;
            } else if (p[j] == '?' || s[i] == p[j]) {
                i++;j++;
            } else {
                if (star == -1) return false;
                j = star + 1;
                i = ++pre;
            }
        }
        for (; p[j] == '*'; j++);
        return j == m;
    }
};
