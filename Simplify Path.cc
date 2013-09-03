class Solution {
public:
    string simplifyPath(string path) {
        path = path + "/";
        stack<string> sta;        
        size_t i = 0, j = 0;
        while (true) {
            j = path.find_first_of('/', i);
            if (j == string::npos) break;                
            string cur = path.substr(i, j - i);            
            if (cur == "..") {
                if (!sta.empty()) sta.pop();
            } else if (cur != "" && cur != ".")
                sta.push(cur);
            i = j + 1;
        }
        string ans;
        while (!sta.empty()) {
            ans = "/" + sta.top() + ans;
            sta.pop();
        }
        if (ans.empty()) ans = "/";
        return ans;
    }
};