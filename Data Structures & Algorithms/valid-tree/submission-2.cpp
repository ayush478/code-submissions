class Solution {
public:
    bool isCycle(int u, int par, vector<vector<int>>& adj, vector<bool> &vis) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (v == par) continue;
            if (vis[v]) return true;
            if (isCycle(v, u, adj, vis)) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        int cnt = 0;

        // Add both directions to make it an undirected graph
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                if (isCycle(i, -1, graph, vis)) {
                    return false;
                }
            }
        }

        // A valid tree must be connected and acyclic
        return cnt == 1;
    }
};
