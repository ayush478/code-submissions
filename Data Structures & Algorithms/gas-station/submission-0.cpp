class Solution {
public:
    // https://chatgpt.com/share/683aa16e-76ac-8012-bea1-43aa982bb270
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),tank=0,start=0,total=0;
        for(int i=0;i<n;i++){
            int consume=gas[i]-cost[i];
            tank+=consume;
            if(tank<0){
                start=i+1; //i+1 kyunki iske pehle wale sare index se start karna bekar he agar 1 shuru kiya tha aur 4th pe tank negative hua he to 2 aur 3 se start karne par to aur negative hoga kyunki 1 se positive start kiya tha to positive aur kam ho jayega
                tank=0;
            }
            total+=consume;
        }
        return total>=0 ? start : -1;//imagin ethis condition gas = [1,2,3,4,5], cost = [3,4,5,6,7] in this we will never be able to  start from any index bcz total is negative that's why we are using total variable
    }
};
