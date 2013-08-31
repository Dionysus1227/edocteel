class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> pos;
        for (int i = 0; i < numbers.size(); i++) {
            pos[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); i++) {
            auto it = pos.find(target - numbers[i]);
            if (it != pos.end() && i < it->second)                
                return {i + 1, it->second + 1};
                
        }
        return vector<int>();
    }
};
