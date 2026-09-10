class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};
    vector<vector<int>> memo;
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = 1; //current cell

        for (int k = 0; k < 4; k++) {
            int nx = i + dir[k];
            int ny = j + dir[k + 1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || matrix[nx][ny] <= matrix[i][j]) {
                continue;
            }

            res = max(res, 1 + solve(nx, ny, n, m, matrix));
        }

        return memo[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(solve(i, j, n, m, matrix), ans);
            }
        }
        return ans;
    }
};
