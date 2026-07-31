class Solution {
   public:
    bool isValid(int row, int col, vector<string>& board, int n) {
        // upper diagonal
        int i = row-1, j = col-1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // lower diagonal
        i = row+1, j = col-1;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        // in row back side
        i = row, j = col-1;
        while (j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            j--;
        }

        return true;
    }
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, ans, board, n);

        return ans;
    }
};
