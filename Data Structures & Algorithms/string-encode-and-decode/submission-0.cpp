class Solution {
   public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& x : strs) {
            res += to_string(x.size()) + '#' + x;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // 1. Find '#'
            while (s[j] != '#') j++;

            // 2. Get length
            int len = stoi(s.substr(i, j - i));

            // 3. Move to string
            i = j + 1;

            // 4. Take substring
            ans.push_back(s.substr(i, len));

            // 5. Move ahead
            i += len;
        }

        return ans;
    }
};
