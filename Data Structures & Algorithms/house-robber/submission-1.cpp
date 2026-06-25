class Solution {
   public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0) return 0;
        if (dp[ind] != -1) return dp[ind];
        int pick = solve(ind - 2, nums, dp) + nums[ind];
        int skip = solve(ind - 1, nums, dp) + 0;
        return dp[ind] = max(pick, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};
