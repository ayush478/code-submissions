class Solution {
   public:
    int jump(vector<int>& nums) {
        int farthest = 0, currReach = 0, cnt = 0, n = nums.size();
        if (n <= 1) return 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (currReach == i) {
                cnt++;
                currReach = farthest;
                if (currReach >= n - 1) break;
            }
        }
        return cnt;
    }
};