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
    bool solve(TreeNode* root, int minValue, int maxValue) {
        if (!root) return true;
        if (root->val <= minValue || root->val >= maxValue) return false;
        return solve(root->left, minValue, root->val) && solve(root->right, root->val, maxValue);
    }
    bool isValidBST(TreeNode* root) { return solve(root, INT_MIN, INT_MAX); }
};
