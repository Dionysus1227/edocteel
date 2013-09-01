class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        bool sign = (dividend > 0) ^ (divisor > 0);   
        long long l_dividend = abs((long long)dividend);
        long long l_divisor = abs((long long)divisor);
        long long ans = Divide(l_dividend, l_divisor);
        if (sign) return -ans;
        else return ans;
    }
private:
    long long Divide(long long &dividend, const long long divisor) {
        if (dividend < divisor) return 0;
        long long res = Divide(dividend, divisor + divisor);
        res = res + res;
        if (dividend >= divisor) {
            res++;
            dividend -= divisor;
        }
        return res;
    }
};
