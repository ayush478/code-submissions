class Solution {
   public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ans = 0, maxf = 0;
        int n = s.size();
        unordered_map<int, int> mp;

        while (j < n) {
            mp[s[j]]++;
            maxf = max(mp[s[j]], maxf);
            while (j - i + 1 - maxf > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
