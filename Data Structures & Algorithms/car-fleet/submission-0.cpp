class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> res;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            res.push_back({position[i], speed[i]});
        }
        sort(res.begin(), res.end(), greater<pair<int, int>>());

        vector<double> stack;
        for (auto& x : res) {
            int pos = x.first;
            int sp = x.second;

            double t = (double)(target - pos) / sp;

            if (stack.empty() || stack.back() < t) {
                stack.push_back(t);
            }
        }
        return stack.size();
    }
};
