class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // Stores indices (not values) of potential max elements
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() &&
                dq.front() == i - k)  // if the maximum element is out of the window pop it out
                dq.pop_front();

            while (!dq.empty() &&
                   nums[dq.back()] < nums[i])  // bada element aagya ab bina kisi tension ke chote
                                               // elements ko nikaldo
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
