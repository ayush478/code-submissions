class Solution {
   public:
    double myPow(double x, int n) {
        long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }

   private:
    double fastPow(double x, long n) {
        if (n == 0) return 1.0;

        double t = fastPow(x, n / 2);

        if (n % 2 == 1) {
            return x * t * t;  
        } else {
            return t * t;
        }
    }
};