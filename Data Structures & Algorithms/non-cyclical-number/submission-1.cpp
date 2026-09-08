class Solution {
   public:
    int digitSqSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            int x = digitSqSum(n);
            cout << x << " " << n << endl;
            n = x;
            if (x == 1) {
                return true;
            }
            if (s.find(x) != s.end()) {
                return false;
            }
            s.insert(x);
        }
        return false;
    }
};
