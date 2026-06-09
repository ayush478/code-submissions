class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxpr = 1, best = INT_MIN;
        int minpr = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                swap(maxpr, minpr);
            }
            maxpr = max(maxpr * nums[i], nums[i]);
            minpr = min(minpr * nums[i], nums[i]);
            best = max(best, maxpr);
        }
        return best;
    }
};