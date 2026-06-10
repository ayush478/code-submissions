class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> minDist(n, 1e9);

        // {stops, {node, cost}}
        queue<p> q;

        q.push({0, {src, 0}});
        minDist[src] = 0;

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int stops = curr.first;
            int node  = curr.second.first;
            int dist  = curr.second.second;

            if (stops > k) continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                int edgeWt  = it.second;

                if (dist + edgeWt < minDist[adjNode]) {

                    minDist[adjNode] = dist + edgeWt;

                    q.push({
                        stops + 1,
                        {adjNode, dist + edgeWt}
                    });
                }
            }
        }

        return minDist[dst] == 1e9 ? -1 : minDist[dst];
    }
};