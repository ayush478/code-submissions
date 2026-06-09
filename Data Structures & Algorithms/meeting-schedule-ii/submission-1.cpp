/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        int n=intervals.size();
        for (auto& x : intervals) {
            start.push_back(x.start);
            end.push_back(x.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0,rooms=0;
        int ans = 0;
        while (i < n && j < n) {
            if (start[i] < end[j]) {
                rooms++;
                i++;
            } else {
                rooms--;
                j++;
            }
            ans=max(ans,rooms);
        }

        return ans;
    }
};
