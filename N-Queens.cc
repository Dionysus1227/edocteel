class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        if (n == 0) return ans;
        vector<int> position;
        Search(position, n, 0, 0 , 0, ans);
        return ans;
    }
private:
    void Search(vector<int> &pos, const int n, int left, int right, int vertical, 
        vector<vector<string>> &ans) {
        if (pos.size() == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (pos[i] == (1 << j)) {
                        board[i][j] = 'Q';
                        break;
                    }                
            ans.push_back(board);
            return;
        }
        int full = (1 << n) - 1;
        int candicate = full & ~(left | right | vertical);
        while (candicate) {
            int cur = candicate & -candicate;
            candicate =  candicate & (candicate - 1);
            pos.push_back(cur);
            Search(pos, n, (left | cur) << 1, (right | cur) >> 1, vertical | cur, ans);
            pos.pop_back();
        }
    }
};