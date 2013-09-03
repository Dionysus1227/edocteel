class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int> > > hash;
        int n = num.size();
        for (int i = n - 2; i >= 0; i--)
            if (num[i] == num[i + 1]) {
                if (i == n - 2 || num[i + 2] != num[i])
                    hash[num[i] + num[i + 1]].push_back(make_pair(i, i + 1));
            } else for (int j = i + 1; j < n; j++)
                if (num[j] != num[j - 1])
                    hash[num[i] + num[j]].push_back(make_pair(i, j));
        vector<vector<int> > ans;
        for (int i = 0; i < n - 3; i++)
            if (i == 0 || num[i] != num[i - 1])
                for (int j = i + 1; j < n - 2; j++)
                    if (j == i + 1 || num[j] != num[j - 1])
                        for (auto &other :hash[target - num[i] - num[j]]) {
                            if (j >= other.first) break;
                            ans.push_back({num[i], num[j], num[other.first], num[other.second]});
                        }
        return ans;
    }
};