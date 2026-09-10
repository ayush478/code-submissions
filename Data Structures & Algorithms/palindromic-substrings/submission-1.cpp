class Solution {
   public:
    int countUtil(int l, int r, string& s) {
        int n = s.size();
        int cnt = 0;
        while (l >= 0 && r < n && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += countUtil(i, i, s);
            res += countUtil(i, i + 1, s);
        }
        return res;
    }
};
