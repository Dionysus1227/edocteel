class Solution {
public:
    bool isNumber(const char *s) {
        string str(s);
        size_t head = str.find_first_not_of(' ');
        if (head == string::npos) return false;
        size_t tail = str.find_last_not_of(' ');
        str = str.substr(head, tail - head + 1);        
        size_t e = str.find('e');
        if (e == string::npos)
            return IsValid(str, 1);
        else return IsValid(str.substr(0, e), 1) && IsValid(str.substr(e + 1), 0);
    }
private:
    
    bool IsValid(const string s, const int dot_max_cnt) {
        if (s.empty()) return false;
        int i = s[0] == '+' || s[0] == '-' ? 1 : 0;        
        int dot_cnt = 0;
        bool num = false;
        for (; i < s.size(); i++)
            if (s[i] == '.') {
                dot_cnt++;
            } else if ('0' <= s[i] && s[i] <= '9')
                        num = true;
                else return false;
        return num && dot_cnt <= dot_max_cnt;
    }
};