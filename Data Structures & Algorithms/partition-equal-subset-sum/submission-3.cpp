class Solution {
   public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return 1;
        }

        if (ind == 0) {
            return nums[0] == target;
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        bool notTake = solve(ind - 1, target, nums, dp);

        bool take = false;
        if (nums[ind] <= target) {
            take = solve(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        if (sum & 1) {
            return false;
        }

        sum /= 2;

        int target = sum;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, target, nums, dp);
    }
};
