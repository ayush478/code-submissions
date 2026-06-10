class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int dir[5] = {0, -1, 0, 1, 0};
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int newR = a + dir[k];
                    int newC = b + dir[k + 1];
                    if (newR < 0 || newC < 0 || newR >= n || newC >= m || grid[newR][newC] != 1) {
                        continue;
                    }
                    q.push({newR, newC});
                    grid[newR][newC] = 2;
                    fresh--;
                }
            }
            if (!q.empty()) ans++;
        }

        return fresh == 0 ? ans : -1;
    }
};
