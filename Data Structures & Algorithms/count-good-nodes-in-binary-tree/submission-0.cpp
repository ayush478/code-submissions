/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    void dfs(TreeNode* root, int mx, int& cnt) {
        if (!root) return;
        if (root->val >= mx) cnt++;
        mx = max(mx, root->val);

        dfs(root->left, mx, cnt);
        dfs(root->right, mx, cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0, mx = INT_MIN;
        dfs(root, mx, cnt);
        return cnt;
    }
};
