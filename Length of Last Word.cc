class Solution {
public:
    int lengthOfLastWord(const char *s) {        
        string str(s);        
        int start = str.find_last_not_of(' ');
        if (start == string::npos) return 0;
        int end = str.find_last_of(' ', start);
        if (end == string::npos) return start + 1;
        return start - end;        
    }
};