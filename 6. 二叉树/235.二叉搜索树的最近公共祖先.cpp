/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root->val > p->val && root->val > q->val) {
            return lowestComAncestor(root->left, p, q);
        }
            
        if (root->val < p->val && root->val < q->val) {
            return lowestComAncestor(root->right, p, q);
        }
        return root;
    }
};
// @lc code=end
