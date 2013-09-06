class Solution {
public:
    bool isValid(string s) {
        stack<char> pre;
        int flag = 0;
        for (char &ch : s) {
            if (ch == ')') {
                if (pre.empty() || pre.top() != '(') return false;
                pre.pop();
            } else if (ch == ']') {
                if (pre.empty() || pre.top() != '[') return false;
                pre.pop();
            } else if (ch == '}') {
                if (pre.empty() || pre.top() != '{') return false;
                pre.pop();
            } else pre.push(ch);                
        }
        return pre.empty();
    }
};