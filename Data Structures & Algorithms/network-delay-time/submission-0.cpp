class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& x : times) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node]) {
                continue;
            }

            for (auto& nei : adj[node]) {
                int adjNode = nei.first;
                int edgeWt = nei.second;
                if (edgeWt + dist[node] < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < n + 1; i++) {//indexing is 1 based
            if (dist[i] == 1e9) {
                return -1;
            }
            ans = max(dist[i], ans);
        }
        return ans;
    }
};