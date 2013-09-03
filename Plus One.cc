class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry) {
            vector<int> ans(digits.size() + 1);
            ans[0] = 1;
            return ans;
        } else return digits;        
    }
};