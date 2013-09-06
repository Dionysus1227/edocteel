class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> hash;
        vector<string> ans;
        for (string &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);            
        }
        for (auto pair : hash)
            if (pair.second.size() > 1)
                ans.insert(ans.end(), pair.second.begin(), pair.second.end());                
        return ans;                
    }   
};