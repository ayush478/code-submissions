class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int g) {
        map<int, int> mp;
        for (auto x : hand) {
            mp[x]++;
        }

        while (mp.size() != 0) {
            auto val = mp.begin()->first;
            
            for (int i = val; i < val + g; i++) {
                if (!mp[i]) return false;
                mp[i]--;
                if (mp[i] == 0) mp.erase(i);
            }
        }
        return true;
    }
};