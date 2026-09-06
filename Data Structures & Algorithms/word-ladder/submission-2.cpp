class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        if (!s.contains(endWord)) return 0;
        queue<string> q;
        s.erase(beginWord);
        q.push(beginWord);

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            for (int i = 0; i < sz; i++) {
                string word = q.front();
                cout<<word<<endl;
                if (word == endWord) {
                    return steps;
                }
                q.pop();
                for (int j = 0; j < word.size(); j++) {
                    char temp = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (s.find(word) != s.end()) {
                            s.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = temp;
                }
            }
        }
        return 0;
    }
};
