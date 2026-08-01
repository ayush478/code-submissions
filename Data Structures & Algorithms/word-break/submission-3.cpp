class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto& w : wordDict) maxLen = max(maxLen, (int)w.size());

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= min(n, i + maxLen); j++) {
                if (dp[j] && dict.count(s.substr(i, j - i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};