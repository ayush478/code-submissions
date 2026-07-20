class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> prevSmall(n, -1), nextSmall(n, n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = nextSmall[i] - prevSmall[i] - 1;
            ans = max(width * heights[i], ans);
        }
        return ans;
    }
};