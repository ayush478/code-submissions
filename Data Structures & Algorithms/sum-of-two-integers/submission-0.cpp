class Solution {
public:
    //https://chatgpt.com/share/683f4585-7dcc-8012-b0ce-328cde9541e6
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
