class Solution {
   public:
    // diag1[row+col] = "used" for anti-diagonals (↗ direction)
    // diag2[row-col+n-1] = "used" for main diagonals (↘ direction), shifted to avoid negative index
    vector<bool> rowUsed, diag1Used, diag2Used;

    bool isValid(int row, int col, int n) {
        return !rowUsed[row] && !diag1Used[row + col] && !diag2Used[row - col + n - 1];
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isValid(row, col, n)) {
                board[row][col] = 'Q';
                rowUsed[row] = diag1Used[row + col] = diag2Used[row - col + n - 1] = true;

                solve(col + 1, ans, board, n);

                board[row][col] = '.';
                rowUsed[row] = diag1Used[row + col] = diag2Used[row - col + n - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        rowUsed.assign(n, false);
        diag1Used.assign(2 * n - 1, false);
        diag2Used.assign(2 * n - 1, false);

        solve(0, ans, board, n);
        return ans;
    }
};