class Solution {
   public:
    double myPow(double x, int n) {
        long N = n;  // ✅ ONLY CHANGE: Convert to long

        if (N == 0) {
            return 1;
        }

        double t = myPow(x, N / 2);  // ✅ Use N instead of n

        if (N % 2) {
            return N < 0 ? 1 / x * t * t : x * t * t;  // ✅ Use N instead of n
        } else {
            return t * t;
        }
    }
};