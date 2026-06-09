class Solution {
   public:
    void solve(int ind, vector<vector<int>>& ans, vector<int>& path, vector<int>& nums,
               int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            if(target>=nums[i]){
                path.push_back(nums[i]);
                solve(i,ans,path,nums,target-nums[i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        solve(0, ans, path, nums, target);
        return ans;
    }
};
