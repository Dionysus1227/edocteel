class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans(num1.size() + num2.size());
        for (int i = 0; i < num1.size(); i++) {
            int carry = 0;
            for (int j = 0; j < num2.size() || carry > 0; j++) {
                if (j < num2.size())
                    ans[i + j] += (num1[i] - '0') * (num2[j] - '0');                
                ans[i + j] += carry;
                carry = ans[i + j] / 10;
                ans[i + j] %= 10;                
            }
        }
        string res;
        bool flag = false;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == 0 && !flag && i > 0) continue;
            flag = true;
            res += ('0' + ans[i]);
        }
        return res; 
    }
};
