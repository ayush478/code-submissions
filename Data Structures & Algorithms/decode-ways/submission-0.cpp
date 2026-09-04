class Solution {
public:
    int solve(int i,string &s, vector<int> &memo){
        if(i==s.size()){
            return 1;
        }
        if(s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];

        int one=0,two=0;
        one = solve(i+1,s,memo);
        
        if(i+1<s.size()){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                two = solve(i+2,s,memo);
            }
        }
        return memo[i] = one+two;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return solve(0,s,memo);
    }
};
