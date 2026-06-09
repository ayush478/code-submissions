class Solution {
   public:
    int solve(int ind, vector<int>& coins, int amount) {
        if (ind == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }
            else return 1e9;
        }
        int notTake = solve(ind - 1, coins, amount);
        int take = 1e9;
        if (amount >= coins[ind]) {
            take = 1 + solve(ind, coins, amount - coins[ind]);
        }
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = INT_MAX;
        ans = solve(n - 1, coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};
