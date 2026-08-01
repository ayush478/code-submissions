class TrieNode {
   public:
    TrieNode* children[128];
    bool endOfWord;
    TrieNode() {
        for (int i = 0; i < 128; i++) children[i] = NULL;
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;

   public:
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (auto& ch : word) {
            if (curr->children[ch] == NULL) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }

    TrieNode* getRoot() { return root; }
};

class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};

    void solve(vector<vector<char>>& board, vector<string>& ans, int i, int j, TrieNode* node,
               string& res) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*') return;

        TrieNode* next = node->children[board[i][j]];
        if (next == NULL) return;  // prune

        res += board[i][j];
        if (next->endOfWord) {
            ans.push_back(res);
            next->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            solve(board, ans, i + dir[k], j + dir[k + 1], next, res);
        }
        board[i][j] = temp;

        res.pop_back();  // Backtrack the string. `res` is passed by reference, so we must
                         // undo the append before returning. This avoids copying the
                         // string in every recursive call.
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree trie;
        for (auto& w : words) trie.insert(w);

        vector<string> ans;
        int n = board.size(), m = board[0].size();
        string res = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(board, ans, i, j, trie.getRoot(), res);
            }
        }
        return ans;
    }
};