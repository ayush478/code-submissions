class Solution {
public:
    bool solve(int ind, const string& s, unordered_set<string>& words, vector<int>& dp) {
        if (ind >= s.size()) return true;
        if (dp[ind] != -1) return dp[ind];

        for (int i = ind; i < s.size(); i++) {
            string sub = s.substr(ind, i - ind + 1);
            if (words.find(sub)!=words.end()) {
                if (solve(i + 1, s, words, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, words, dp);
    }
};