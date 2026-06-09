class Solution {
   public:
#define p pair<int, int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<p> pq;
        for (auto& x : mp) {
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        while (!pq.empty() && k--) {
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
