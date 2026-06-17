class Solution {
   public:
    // Let's see a more interesting example.

    // Difference:

    // [+2, -1, -4, +5]

    // Start at 0:

    // Station 0:
    // total = 2

    // Station 1:
    // total = 1

    // Station 2:
    // total = -3

    // We fail at index 2.

    // Visualization:

    // start
    //   |
    //   v

    // 0 ---- 1 ---- 2
    // +2    -1    -4

    // Running sum:

    // 2
    // 1
    // -3  ❌
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);
        if (total < 0) return -1;
        int curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr += gas[i] - cost[i];
            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
