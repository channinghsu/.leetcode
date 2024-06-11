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
   private:
    TreeNode* pre = nullptr;
    int res = __INT_MAX__;
    // 中序遍历将二叉搜索树转换为
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        // 左
        traversal(cur->left);
        // 中
        if (pre != nullptr)
            res = min(res, cur->val - pre->val);
        pre = cur;
        // 右
        traversal(cur->right);
    }

   public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};
// @lc code=end
