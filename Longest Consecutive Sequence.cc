class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hash;
        int ans = 0;
        for (int val : num)
            hash[val] = 1;
        for (int val : num) {
            if (hash.find(val) == hash.end()) continue;
            for (int i = val + 1; hash.find(i) != hash.end(); i++) {
                hash[val] += hash[i];
                hash.erase(i);
            }
            ans = max(ans, hash[val]);                        
        }
        return ans;
    }
};