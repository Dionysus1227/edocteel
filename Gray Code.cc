class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int> ans(1, 0);
       for (int i = 0; i < n; i++)
        for (int j = ans.size() - 1; j >= 0; j--)
            ans.push_back((1 << i) + ans[j]);
        return ans;    
    }
};