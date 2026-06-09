class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), suff(n, 0);
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
            suff[n - i - 1] = suff[n - i] * nums[n - i - 1];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = (i - 1 >= 0 ? pre[i - 1] : 1) * (i + 1 < n ? suff[i + 1] : 1);
        }
        return ans;
    }
};
