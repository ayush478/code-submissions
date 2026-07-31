class Solution {
   public:
    int solve(vector<vector<int>>& dp, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(dp, m, n, i + 1, j) + solve(dp, m, n, i, j + 1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, m, n, 0, 0);
    }
};
