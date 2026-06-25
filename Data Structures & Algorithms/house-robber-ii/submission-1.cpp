class Solution {
   public:
    int solve(int start, int end, vector<int>& nums) {
        int prev2 = 0;  // max sum ending 2 houses ago
        int prev1 = 0;  // max sum ending 1 house ago
        for (int i = start; i <= end; i++) {
            int temp = prev1;
            prev1 = max(prev1, nums[i] + prev2);
            prev2 = temp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(solve(0, n - 2, nums), solve(1, n - 1, nums));
    }
};
