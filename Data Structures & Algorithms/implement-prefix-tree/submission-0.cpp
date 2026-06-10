class TrieNode {
   public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
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
            if (curr->children[ch - 'a'] == NULL) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (curr->children[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto ch : prefix) {
            if (curr->children[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};
