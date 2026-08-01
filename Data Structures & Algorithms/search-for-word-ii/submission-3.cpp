#include <vector>
#include <string>
using namespace std;

class TrieNode {
   public:
    TrieNode* children[128];  // indexed directly by char value — no subtraction, no bounds risk
    bool endOfWord;
    TrieNode() {
        for (int i = 0; i < 128; i++) {
            children[i] = NULL;
        }
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
            unsigned char idx = (unsigned char)ch;
            if (curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    TrieNode* getRoot() { return root; }
};

class Solution {
   public:
    vector<int> dir = {0, -1, 0, 1, 0};

    void solve(vector<vector<char>>& board, vector<string>& ans, int i, int j, TrieNode* node,
               string res) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*') return;

        unsigned char idx = (unsigned char)board[i][j];
        TrieNode* next = node->children[idx];
        if (next == NULL) return;  // prune: no dictionary word continues with this letter

        res += board[i][j];
        if (next->endOfWord) {
            ans.push_back(res);
            next->endOfWord = false;  // prevent duplicate matches
        }

        char temp = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            solve(board, ans, i + dir[k], j + dir[k + 1], next, res);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree trie;
        for (auto& w : words) trie.insert(w);

        vector<string> ans;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(board, ans, i, j, trie.getRoot(), "");
            }
        }
        return ans;
    }
};