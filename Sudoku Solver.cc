class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<int> pos;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') pos.push_back(i * 9 + j);
        Search(board, pos, 0);
    }
private:
    bool Search(vector<vector<char> > &board, const vector<int> &pos, int index) {
        if (index == pos.size()) return true;
        int x = pos[index] / 9;
        int y = pos[index] % 9;
        vector<bool> valid(9, true);        
        for (int i = 0; i < 9; i++)
            if (board[i][y] != '.') valid[board[i][y] - '1'] = false;
        for (int j = 0; j < 9; j++)
            if (board[x][j] != '.') valid[board[x][j] - '1'] = false;            
        for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
            for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
                if (board[i][j] != '.') valid[board[i][j] - '1'] = false;      
        for (int i = 0; i < 9; i++)
            if (valid[i]) {
                board[x][y] = '1' + i;
                if (Search(board, pos, index + 1)) return true;
            }
        board[x][y] = '.';
        return false;
    }
};