/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if (root == nullptr || root == p || root == q) return root;
        root->left = lowestCommonAncestor(root->left,p,q);
        root->right = lowestCommonAncestor(root->right,p,q);

        if (root->left && root->right) return root;
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        return nullptr;
    }
};
// @lc code=end

