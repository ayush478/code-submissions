class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n1 = num1.length(), n2 = num2.length();
        vector<int> res(n1 + n2, 0);

        for (int i2 = n2 - 1; i2 >= 0; i2--) {
            for (int i1 = n1 - 1; i1 >= 0; i1--) {
                int digit = (num1[i1] - '0') * (num2[i2] - '0');

                int pos = (n1 - 1 - i1) + (n2 - 1 - i2);

                res[pos] += digit;
                res[pos + 1] += res[pos] / 10;
                res[pos] %= 10;
            }
        }

        string result = "";
        int i = res.size() - 1;
        while (i >= 0 && res[i] == 0) {
            i--;
        }
        while (i >= 0) {
            result += char('0' + res[i--]);
        }
        return result;
    }
};