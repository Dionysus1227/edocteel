class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> digit(32);
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < n; j++)
                digit[i] += ((A[j] >> i) & 1);
        int ans = 0;
        for (int i = 0; i < 32; i++)
            ans |= (digit[i] % 3) << i;
        return ans;
    }
};
