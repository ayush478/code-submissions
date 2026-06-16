class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        int i = 1, cnt = 0, n = intervals.size();
        vector<int> prev = intervals[0];
        while (i < n) {
            if (prev[1] > intervals[i][0]) {
                cnt++;
            } else {
                prev = intervals[i];
            }
            i++;
        }
        return cnt;
    }
};
