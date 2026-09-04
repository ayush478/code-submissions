class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        // k - starting row index   n - ending row index
        // l - starting column index   m - ending column index
        vector<int> ans;
        int n = A.size();
        int m = A[0].size();
        int k = 0, l = 0;
        while (k < n && l < m) {
            // print first (top) row
            for (int i = l; i < m; i++) {
                ans.push_back(A[k][i]);
            }
            k++;
            // print last (right) column
            for (int i = k; i < n; i++) {
                ans.push_back(A[i][m - 1]);
            }
            m--;
            // print last (bottom) row
            if (k < n) {  // guard: avoid re-printing
                for (int i = m - 1; i >= l; i--) {
                    ans.push_back(A[n - 1][i]);
                }
                n--;
            }
            // print first (left) column
            if (l < m) {  // guard: avoid re-printing
                for (int i = n - 1; i >= k; i--) {
                    ans.push_back(A[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};
