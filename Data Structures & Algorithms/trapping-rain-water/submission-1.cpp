class Solution {
   public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1, leftMax = arr[0], rightMax = arr[n-1], ans = 0;
        while (l <= r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] >= leftMax) {
                    leftMax = arr[l];
                } else {
                    ans += leftMax - arr[l];
                }
                l++;
            } else {
                if (arr[r] >= rightMax) {
                    rightMax = arr[r];
                } else {
                    ans += rightMax - arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};
