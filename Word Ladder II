class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {        
        unordered_map<string, vector<string> > pre;        
        BFS(end, start, dict, pre);
        vector<vector<string>> ans;
        vector<string> cur;
        DFS(start, end, pre, cur, ans);        
        return ans;
    }
private:
    void DFS(const string &start, const string &end, unordered_map<string, vector<string> > &pre, 
        vector<string> &cur, vector<vector<string> > &ans) {
            cur.push_back(start);
            if (start == end) {
                ans.push_back(cur);
                cur.pop_back();
                return;
            }
            for (string next : pre[start]) {                
                DFS(next, end, pre, cur, ans);
            }
            cur.pop_back();
        }

    void BFS(const string &start, const string &end, const unordered_set<string> &dict, 
        unordered_map<string, vector<string> > &pre) {
        queue<string> q;
        unordered_map<string, int> step;
        q.push(start);
        step[start] = 0;
        while (!q.empty()) {
            string src = q.front();            
            if (src == end) break;
            q.pop();
            string cur = src;            
            for (int i = 0; i < cur.size(); i++) {
                char bak = cur[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == bak) continue;
                    cur[i] = ch;
                    if (dict.find(cur) != dict.end()) {
                        if (step.find(cur) == step.end()) {
                            q.push(cur);
                            step[cur] = step[src] + 1;
                            pre[cur].push_back(src);
                        } else if (step[cur] == step[src] + 1)
                            pre[cur].push_back(src);
                    }
                }
                cur[i] = bak;
            }
        }
    }
};
