class Solution {
   public:
    bool isVectorEqual(vector<int>& A, vector<int>& B) {
        for (int i = 0; i < 26; i++) {
            if (A[i] != B[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);  // discuss section

        int i = 0, j = 0;
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }

        while (j < s2.size()) {
            freq2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size()) {
                if (isVectorEqual(freq1, freq2)) return true;
            }

            if (j - i + 1 < s1.size())
                j++;
            else {
                freq2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
