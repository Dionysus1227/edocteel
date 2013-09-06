class Solution {
public:
    string countAndSay(int n) {
        string pre;
        string cur = "1";
        for (int i = 1; i < n; i++) {
            pre = cur;
            cur = "";
            for (int j = 0, k = 0; j < pre.size(); j += k) {
                for (k = 0; j + k < pre.size() && pre[j + k] == pre[j]; k++);
                cur += to_string(k) +to_string(pre[j] - '0');
            }
        }
        return cur;        
    }
};