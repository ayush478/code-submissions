class Solution {
   public:
    bool isPalindrome(int start, int end, string s) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& res, string& s, int ind) {
        if (ind >= s.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(ind, i, s)) {
                res.push_back(s.substr(ind, i - ind + 1));
                solve(ans, res, s, i + 1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        solve(ans, res, s, 0);
        return ans;
    }
};