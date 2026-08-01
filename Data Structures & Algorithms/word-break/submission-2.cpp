class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> mp;
        for (auto& x : wordDict) {
            mp[x]=true;
        }
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=n;j++){
                if(dp[j] && mp[s.substr(i,j-i)]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0]==1;
    }
};
