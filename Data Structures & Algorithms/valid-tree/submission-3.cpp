class Solution {
public:

    bool isCycle(int node, int parent,
                 vector<vector<int>>& graph,
                 vector<bool>& vis) {

        vis[node] = true;

        for (int nei : graph[node]) {

            // Ignore the edge back to parent
            if (nei == parent)
                continue;

            // Visited node other than parent => cycle
            if (vis[nei])
                return true;

            if (isCycle(nei, node, graph, vis))
                return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);

        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        // Build UNDIRECTED graph
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                components++;

                if (isCycle(i, -1, graph, vis))
                    return false;
            }
        }

        return components == 1;
    }
};