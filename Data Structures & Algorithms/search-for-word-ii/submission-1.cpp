class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};

    void solve(unordered_set<string>& s, vector<vector<char>>& board, vector<string>& words,
               vector<string>& ans, int i, int j, string res, int maxLen) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*') {
            return;
        }
        if ((int)res.size() >= maxLen) {   
            return;
        }

        char temp = board[i][j];
        board[i][j] = '*';
        res += temp;

        if (s.count(res)) {
            ans.push_back(res);
            s.erase(res);
        }

        for (int k = 0; k < 4; k++) {
            int newR = i + dir[k];
            int newC = j + dir[k + 1];
            solve(s, board, words, ans, newR, newC, res, maxLen);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        unordered_set<string> s(words.begin(), words.end());

        int maxLen = 0;
        for (auto& w : words) maxLen = max(maxLen, (int)w.size());  

        string res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(s, board, words, ans, i, j, res, maxLen);
            }
        }
        return ans;
    }
};