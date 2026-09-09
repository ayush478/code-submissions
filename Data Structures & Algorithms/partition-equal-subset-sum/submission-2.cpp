class Solution {
   public:
    bool solve(int sum, vector<int>& nums, int i, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (i == 0) {
            if (nums[0] == sum || nums[0] == 0) {
                return true;
            }
            return false;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        bool take = false;
        if (sum >= nums[i]) take = solve(sum - nums[i], nums, i - 1, dp);
        bool notTake = solve(sum, nums, i - 1, dp);

        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();

        for (auto& x : nums) {
            sum += x;
        }

        if (sum & 1) {
            return false;
        }

        sum /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return solve(sum, nums, n - 1, dp);
    }
};
