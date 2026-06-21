class Solution {
   public:
    void solve(vector<vector<int>>& ans, vector<int>& res, vector<int>& candidates, int target,
               int ind) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if (target >= candidates[i]) {
                res.push_back(candidates[i]);
                solve(ans, res, candidates, target - candidates[i], i + 1);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(ans, res, candidates, target, 0);
        return ans;
    }
};
