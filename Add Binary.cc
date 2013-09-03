class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry > 0; i--,j--) {
            int val = (i >= 0 ? a[i] -'0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            carry = val >> 1;            
            ans.push_back('0' + (val & 1));
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};