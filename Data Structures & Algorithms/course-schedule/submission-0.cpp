class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (auto& a : adj[x]) {
                if (--inDegree[a] == 0) {
                    q.push(a);
                }
            }
        }
        if (res.size() == numCourses) {
            return true;
        }
        return false;
    }
};
