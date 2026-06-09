class Solution {
   public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;  // search space is already sorted then arr[low] will always
                                         // be the minimum in that search space:
            if (target == arr[mid]) return mid;
            if (arr[low] <= arr[mid]) {  // left part sorted
                if (arr[low] <= target && arr[mid] >= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (arr[mid] <= target && arr[high] >= target) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
