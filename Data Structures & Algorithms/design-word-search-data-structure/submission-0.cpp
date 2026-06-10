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

    bool searchInNode(string word, int index, TrieNode* node) {
        if (node == NULL) return false;
        if (index == word.length()) return node->endOfWord;

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchInNode(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return searchInNode(word, index + 1, node->children[ch - 'a']);
        }
    }

    bool search(string word) {
        return searchInNode(word, 0, root);
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

class WordDictionary {
    PrefixTree* prefixTree;

   public:
    WordDictionary() { prefixTree = new PrefixTree(); }

    void addWord(string word) { prefixTree->insert(word); }

    bool search(string word) { return prefixTree->search(word); }
};