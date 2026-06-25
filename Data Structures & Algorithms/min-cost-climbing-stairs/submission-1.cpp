class Solution {
   public:
    int solve(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind >= cost.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int jumpOne = solve(ind + 1, cost, dp) + cost[ind];
        int jumpTwo = 1e9;
        if (ind + 2 <= cost.size()) {
            jumpTwo = solve(ind + 2, cost, dp) + cost[ind];
        }
        return dp[ind] = min(jumpOne, jumpTwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(0, cost, dp),solve(1,cost,dp));
    }
};
