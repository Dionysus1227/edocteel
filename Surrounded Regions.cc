class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    if (board[i][j] == 'O')
                        BFS(board, n, m, i, j, 'O', '#');
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }        
    }
private:
    const int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void BFS(vector<vector<char>> &board, int n, int m, int x, int y, char src, char des) {
        queue<int> q;
        q.push(x * m + y);
        board[x][y] = des;
        while (!q.empty()) {
            x = q.front() / m;
            y = q.front() % m;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int new_x = x + move[k][0];
                int new_y = y + move[k][1];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && board[new_x][new_y] == src) {
                    board[new_x][new_y] = des;
                    q.push(new_x * m +new_y);
                }
            }
        }        
    }
};