class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }

        vector<vector<int>>ans;
        while(!pq.empty() && ans.size()<k){
            auto [x,y]=pq.top();
            pq.pop();
            ans.push_back(points[y]);
        }
        return ans;
    }
};
