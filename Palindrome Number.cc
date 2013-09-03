class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int high = 1;
        for (; x / high >= 10; high *= 10);
        for (int low = 1; low < high; low *= 10, high /= 10)
            if (x / low % 10 != x / high % 10) return false;
        return true;        
    }
};