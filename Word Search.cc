class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        int n = board.size();
        int m = board.size();
        for (int i = 0; i <  board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (Find(board, i, j, word, 0)) return true;
        return false;
    }
private:
    const int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool Find(vector<vector<char> > &board, int x, int y, const string &word, int i) {
        if (i == word.size()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() ||
            board[x][y] != word[i]) return false;
        board[x][y] = 0;
        for (int k = 0; k < 4; k++) {
            if (Find(board, x + move[k][0], y + move[k][1], word, i + 1)) {
                board[x][y] = word[i];
                return true;
            }
        }
        board[x][y] = word[i];
        return false;
    }
};