class Solution {
   public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[i] = 1;
        for (auto& x : adj[i]) {
            if (!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
