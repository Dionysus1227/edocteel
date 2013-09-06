class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0) return;
        int i = num.size() - 2;
        for (; i >= 0 && num[i] >= num[i + 1]; i--);
        if (i >= 0) {
            for (int j = i + 1; j < num.size(); j++)
                if (j + 1 == num.size() || num[j + 1] <= num[i]) {
                    swap(num[i], num[j]);
                    break;
                }
        }
        reverse(num.begin() + i + 1, num.end());
    }
};