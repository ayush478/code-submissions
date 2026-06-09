class Solution {
   public:
    string minWindow(string s, string t) {
        int uniqueWords = 0, n = s.size();
        vector<int> hash(256, 0);

        for (int i = 0; i < t.size(); i++) {
            if (hash[t[i] - 'A'] == 0) uniqueWords++;
            hash[t[i] - 'A']++;
        }
        int i = 0, j = 0, resCount = INT_MAX, resStart = -1;
        while (j < n) {
            hash[s[j] - 'A']--;
            if (hash[s[j] - 'A'] == 0) {
                uniqueWords--;
            }
            while (uniqueWords == 0) {
                if (resCount > j - i + 1) {
                    resCount = j - i + 1;
                    resStart = i;
                }
                hash[s[i] - 'A']++;

                if (hash[s[i] - 'A'] > 0) uniqueWords++;

                i++;
            }
            j++;
        }
        return resStart > -1 ? s.substr(resStart, resCount) : "";
    }
};
