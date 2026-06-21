class Solution {
   public:
    void solve(string& digits, vector<string>& ans, string& res, int ind, vector<string>& mp) {
        if (ind >= digits.size()) {
            ans.push_back(res);
            return;
        }
        int digit = digits[ind] - '0';
        string val = mp[digit];
        for (int i = 0; i < val.size(); i++) {
            res.push_back(val[i]);
            solve(digits, ans, res, ind + 1, mp);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string res = "";
        solve(digits, ans, res, 0, mp);
        return ans;
    }
};
