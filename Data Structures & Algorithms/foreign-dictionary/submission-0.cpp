class Solution {
   public:
    // ye wala question tuf wale se alag he isme lowercase me koi bhi char ho sakta he isiliye
    // unique ka bhi use kiya he
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> indegree(26, -1);

        for (const auto& w : words) {
            for (char c : w) indegree[c - 'a'] = 0;
        }

        vector<vector<char>> adj(256);

        for (int i = 0; i < n - 1; i++) {
            string one = words[i];
            string two = words[i + 1];

            int mini = min(one.size(), two.size());
            if (one.size() > two.size() && one.substr(0, mini) == two.substr(0, mini)) return "";

            for (int j = 0; j < mini; j++) {
                if (one[j] != two[j]) {
                    adj[one[j]].push_back(two[j]);
                    indegree[two[j] - 'a']++;
                    break;
                }
            }
        }
        queue<char> q;
        string ans;
        int uniqueCount = 0;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != -1) {
                uniqueCount++;
                if (indegree[i] == 0) q.push(i + 'a');
            }
        }
        while (!q.empty()) {
            char x = q.front();
            q.pop();
            ans += x;
            for (auto& v : adj[x]) {
                if (--indegree[v - 'a'] == 0) {
                    q.push(v);
                }
            }
        }
        if (ans.size() < uniqueCount) return "";
        return ans;
    }
};
