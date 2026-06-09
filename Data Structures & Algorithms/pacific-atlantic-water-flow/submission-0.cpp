class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(int i, int j, vector<vector<bool>>& ocean, vector<vector<int>>& heights, int n,
             int m) {
        ocean[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int nr = i + dir[k];
            int nc = j + dir[k + 1];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m || ocean[nr][nc] ||
                heights[i][j] > heights[nr][nc]) {
                continue;
            }
            dfs(nr, nc, ocean, heights, n, m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for (int c = 0; c < m; c++) {
            dfs(0, c, pac, heights, n, m);
            dfs(n - 1, c, atl, heights, n, m);
        }

        for (int r = 0; r < n; r++) {
            dfs(r, 0, pac, heights, n, m);
            dfs(r, m - 1, atl, heights, n, m);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
