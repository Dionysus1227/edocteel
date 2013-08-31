class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, int> step;
        q.push(start);
        step[start] = 1;
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
                        }
                    }
                }
                cur[i] = bak;
            }
        }
        return step[end];
    }
};
