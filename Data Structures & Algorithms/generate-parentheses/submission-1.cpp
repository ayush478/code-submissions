class Solution {
   public:
    void solve(vector<string>& ans, string res, int n, int c, int o) {
        if (o == n && c == n) {
            ans.push_back(res);
            return;
        }
        if (o < n) {
            solve(ans, res + '(', n, c, o + 1);
        }
        if (c < o) {
            solve(ans, res + ')', n, c + 1, o);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        int c = 0, o = 0;
        solve(ans, res, n, c, o);
        return ans;
    }
};
