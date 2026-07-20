class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;

        while (!q.empty()) {
            int k = q.front();
            q.pop();
            order.push_back(k);
            for (auto& x : graph[k]) {
                if (--indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        return order.size() == numCourses ? order : vector<int>{};
    }
};
