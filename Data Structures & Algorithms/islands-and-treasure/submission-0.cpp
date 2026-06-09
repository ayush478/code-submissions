class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int res) {
        // Boundary and wall check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1) return;

        // If this cell already has a shorter distance, stop
        if (grid[i][j] < res) return;

        // Update the current cell with the current distance
        grid[i][j] = res;

        // Recurse in 4 directions with incremented distance
        dfs(i + 1, j, n, m, grid, res + 1);
        dfs(i - 1, j, n, m, grid, res + 1);
        dfs(i, j + 1, n, m, grid, res + 1);
        dfs(i, j - 1, n, m, grid, res + 1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, n, m, grid, 0); // Start distance at 0 for each gate
                }
            }
        }
    }
};
