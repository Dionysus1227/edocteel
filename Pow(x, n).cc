const double eps = 1e-8;  
class Solution {
public: 
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (fabs(x) < eps) return 0;
        double sub = pow(x, n / 2);
        double res = sub * sub;
        if (n % 2 != 0) 
            res *= n > 0 ? x : 1.0 / x;
        return res;                
    }
};