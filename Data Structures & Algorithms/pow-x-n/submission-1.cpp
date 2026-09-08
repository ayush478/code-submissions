class Solution {
   public:
    double myPow(double x, int n) {
        double ans = 1;
        long nn = n;

        if (nn < 0) {  // for avoiding integer overflow
            nn *= -1;
        }
        
        while (nn > 0) {
            if (nn & 1) {
                ans = ans * x;
                nn -= 1;
            } else {
                x = x * x;
                nn /= 2;
            }
        }
        if (n < 0) {
            return (double)1.0 / (double)ans;
        }
        return ans;
    }
};