class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        sta.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size() ; i++)
            if (s[i] == '(')
                sta.push(i);
            else {
                sta.pop();
                if (!sta.empty())
                    ans = max(ans, i - sta.top());
                else sta.push(i);                
            }
        return ans;        
    }
};