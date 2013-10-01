class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() != cost.size() || gas.empty()) return -1;
        int delta = 0;
        int index = -1;
        int min_gas = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            delta += gas[i] - cost[i];
            if (delta < min_gas) {
                min_gas = delta;
                index = (i + 1) % gas.size();
            }
        }
        if (delta < 0) index = -1;
        return index;
    }
};
