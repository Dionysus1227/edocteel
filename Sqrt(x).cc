 class Solution {
public:
    int sqrt(int x) {       
       int left = 1, right = x;
       while (left <= right) {
           int mid = left + (right - left >> 1);
           if (mid <= x / mid)  left = mid + 1;
           else right = mid - 1;
       }
        return right;    
    }
};