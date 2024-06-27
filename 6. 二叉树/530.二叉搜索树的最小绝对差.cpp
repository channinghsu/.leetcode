/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
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
    int minInt = INT_MAX;
    TreeNode* pre = nullptr;
    void dfs(TreeNode* cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre != nullptr) {
            minInt = min(minInt, cur->val - pre->val);
        }
        pre = cur;
        dfs(cur->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minInt;
    }
};
// @lc code=end
