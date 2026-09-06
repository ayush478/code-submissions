class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<int> dir = {0, -1, 0, 1, 0};

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == INT_MAX) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
