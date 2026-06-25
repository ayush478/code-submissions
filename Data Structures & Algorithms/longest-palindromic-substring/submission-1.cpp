class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int ans = 0, startIdx = 0;
        string res;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    if (ans < j - i + 1) {
                        ans = j - i + 1;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx, ans);
    }
};