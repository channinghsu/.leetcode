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
        // 递归终止条件：遇到p、q、当前节点为空
        if (root == q || root == p || root == nullptr) return root;
        // 后序遍历全树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        // 若左右不为空，则当前为最近祖先
        if (left != nullptr && right != nullptr) return root;
        // 若左为空，右为最近祖先，反之亦然
        if (left == nullptr) return right;
        return left;
        
        // if (left == nullptr && right != nullptr) return right;
        // else if (left != nullptr && right == nullptr) return left;
        // else return nullptr;

    }
};
// @lc code=end

