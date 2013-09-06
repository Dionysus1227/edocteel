class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());        
        int ans = num[0] + num[1] + num[2];
        for (int i = 0; i <= num.size() - 3; i++) {
            int j = i + 1, k = num.size() - 1;
            while (j < k) {
                if (abs(num[i] + num[j] + num[k] - target) < abs(target - ans))
                    ans = num[i] + num[j] + num[k];
                
                if (num[i] + num[j] + num[k] < target)
                    j++;
                else k--;     
            }
        }
        return ans;
    }
};