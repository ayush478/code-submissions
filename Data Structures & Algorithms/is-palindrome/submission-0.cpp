class Solution {
   public:
    string helper(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i])) {
                continue;
            }
            res += tolower(s[i]);
        }
        return res;
    }
    bool isPalindrome(string s) {
        string res = helper(s);
        int i = 0, j = (int)res.size() - 1;
        while (i < j) {
            if (res[i] != res[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
