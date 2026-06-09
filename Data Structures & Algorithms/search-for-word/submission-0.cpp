class Solution {
   public:
    bool solve(int idx, int i, int j, vector<vector<char>>& board, string word) {
        if (idx >= word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            word[idx] != board[i][j]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool ans = solve(idx + 1, i + 1, j, board, word) || solve(idx + 1, i, j - 1, board, word) ||
                   solve(idx + 1, i - 1, j, board, word) || solve(idx + 1, i, j + 1, board, word);

        board[i][j] = temp;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(0, i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};