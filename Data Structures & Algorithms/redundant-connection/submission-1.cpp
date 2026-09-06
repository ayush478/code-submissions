class DSU {
    vector<int> rank, parent;

   public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    bool unionSets(int a, int b) {
        int ua = findParent(a);
        int ub = findParent(b);

        // Already connected -> cycle
        if (ua == ub) {
            return false;
        }

        // Smaller rank goes under larger rank
        if (rank[ua] < rank[ub]) {
            swap(ua, ub);
        }

        parent[ub] = ua;

        // Equal rank -> height increases
        if (rank[ua] == rank[ub]) {
            rank[ua]++;
        }

        return true;
    }
};

class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& x : edges) {
            if (!dsu.unionSets(x[0], x[1])) {
                return x;
            }
        }
        return {};
    }
};