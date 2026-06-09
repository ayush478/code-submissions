class Solution {
public:
    //https://chatgpt.com/share/68408679-7cd8-8012-ad52-d0c74aa71192
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};