class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestStreak = 0, streak = 0;
        for (auto x : nums) {
            if (!s.count(x - 1)) {
                streak = 1;
                longestStreak = max(longestStreak, streak);
                while (s.count(x+1)) {
                    x++;
                    streak++;
                    longestStreak = max(longestStreak, streak);
                }
            }
        }
        return longestStreak;
    }
};
