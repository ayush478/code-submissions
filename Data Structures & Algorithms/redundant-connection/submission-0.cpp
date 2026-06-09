class Solution {
public:
    // https://chatgpt.com/share/6836f6ea-a028-8012-8c37-ed847ddfd1a5
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> visit(n + 1, false);

            if (dfs(u, -1, adj, visit)) {
                return {u, v};
            }
        }
        return {};
    }

private:
    bool dfs(int node, int parent, 
             vector<vector<int>>& adj, vector<bool>& visit) {
        if (visit[node]) return true;
        visit[node] = true;
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            if (dfs(nei, node, adj, visit)) return true;
        }
        return false;
    }
};