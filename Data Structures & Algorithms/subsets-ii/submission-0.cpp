class Solution {
   public:
    void solve(vector<vector<int>>& ans, vector<int>& res, vector<int>& nums, int ind) {
        ans.push_back(res);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) {
                continue;
            }
            res.push_back(nums[i]);
            solve(ans, res, nums, i + 1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans, res, nums, 0);
        return ans;
    }
};
