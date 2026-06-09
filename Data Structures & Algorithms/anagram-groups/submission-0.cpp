class Solution {
   public:
    string sortStr(string& s) {
        vector<int> hash(26, 0);
        for (auto& x : s) {
            hash[x - 'a']++;
        }
        string res;
        for (int i = 0; i < 26; i++) {
            res += string(hash[i], i + 'a');
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& x : strs) {
            mp[sortStr(x)].push_back(x);
        }
        vector<vector<string>> ans;
        for (auto& x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
