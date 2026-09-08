class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int i = 1, n = intervals.size();

        while (i < n) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                auto [a, b] = mp[s[i]];
                mp[s[i]] = {min(i, a), max(i, b)};
            } else {
                mp[s[i]] = {i, i};
            }
        }

        vector<vector<int>> res;
        for (auto [a, b] : mp) {
            int start = b.first;
            int end = b.second;
            res.push_back({start, end});
        }
        vector<vector<int>> ans = merge(res);
        vector<int> temp;
        for (auto& x : ans) {
            temp.push_back(x[1] - x[0] + 1);
        }
        return temp;
    }
};
