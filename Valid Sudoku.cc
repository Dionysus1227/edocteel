class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> appear(9, false);
        for (int i = 0; i < 9; i++) {
            appear.assign(9, false);
            for (int j = 0; j < 9; j++)
                if (!verify(board[i][j], appear)) return false;
        }
        for (int j = 0; j < 9; j++) {
            appear.assign(9, false);
            for (int i = 0; i < 9; i++)
                if (!verify(board[i][j], appear)) return false;
        }
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++) {
                appear.assign(9, false);
                for (int i = x * 3; i < x * 3 + 3; i++)
                    for (int j = y * 3; j < y * 3 + 3; j++) 
                        if (!verify(board[i][j], appear)) return false;                    
            }
        return true;        
    }
private:
    bool verify(char ch, vector<bool> &appear) {
        if (ch == '.') return true;
        if (appear[ch - '1']) return false;
        appear[ch - '1'] = true;
        return true;
    }
};  