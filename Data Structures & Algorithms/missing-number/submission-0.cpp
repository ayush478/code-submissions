class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int res=n; //ye imp he isse last value ki handling bhi ho jati he
        for(int i=0;i<nums.size();i++){
            res^=i;
            res^=nums[i];
        }
        return res;
    }
};
