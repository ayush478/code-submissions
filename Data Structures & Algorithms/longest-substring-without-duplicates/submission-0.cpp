class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        
        int i=0,j=0,ans=0,n=s.size();
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i++]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
