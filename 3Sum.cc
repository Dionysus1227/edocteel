class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if (num.size() < 3) return ans;
        sort(num.begin(), num.end());        
        for (int i = 0; i <= num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                if (num[j] + num[k] == -num[i])
                    if ((j == i + 1 || num[j] != num[j - 1]) &&
                        (k == num.size() - 1 || num[k] != num[k + 1]))
                        ans.push_back({num[i], num[j], num[k]});
                if (num[i] + num[j] + num[k] < 0)
                    j++;
                else k--;     
            }
        }  
        return ans;
    }
};