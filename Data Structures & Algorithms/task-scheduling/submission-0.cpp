class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        map<char, int> mp;

        for (auto& x : tasks) {
            mp[x]++;
        }
        for (auto& x : mp) {
            pq.push(x.second);
        }

        int ans = 0;
        while (!pq.empty()) {
            int time = 0;
            vector<int> temp;
            int cycle = n + 1;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int count : temp) {
                if (--count > 0) pq.push(count);
            }
            ans += !pq.empty() ? cycle : time;
        }
        return ans;
    }
};
