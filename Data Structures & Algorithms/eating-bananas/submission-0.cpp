class Solution {
   public:
    bool isPossible(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / k;
            if (piles[i] % k != 0) {
                hours++;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
