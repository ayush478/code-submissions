class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++) {  // first row and last row
            dfs(0, i, board);
            dfs(n - 1, i, board);
        }
        for (int i = 0; i < n; i++) {  // first row and last row
            dfs(i, 0, board);
            dfs(i, m - 1, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
