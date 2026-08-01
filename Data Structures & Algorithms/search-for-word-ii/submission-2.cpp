class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};

    void solve(unordered_set<string>& s, vector<vector<char>>& board, vector<string>& ans, int i,
               int j, string& res, int maxLen) {
        int n = board.size(), m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*') return;

        if ((int)res.size() >= maxLen) return;

        char temp = board[i][j];
        board[i][j] = '*';
        res.push_back(temp);

        if (s.count(res)) {
            ans.push_back(res);
            s.erase(res);
        }

        for (int k = 0; k < 4; k++) {
            solve(s, board, ans, i + dir[k], j + dir[k + 1], res, maxLen);
        }

        res.pop_back();      // Backtrack string
        board[i][j] = temp;  // Backtrack board
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        unordered_set<string> s(words.begin(), words.end());

        int maxLen = 0;
        for (auto& w : words) maxLen = max(maxLen, (int)w.size());

        string res;

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(s, board, ans, i, j, res, maxLen);
            }
        }

        return ans;
    }
};