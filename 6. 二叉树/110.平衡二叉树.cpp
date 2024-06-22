/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 计算树的高度，如果树不平衡则返回-1
    int getHight(TreeNode* root){
        if (root == nullptr) return 0;
        int left = getHight(root->left);
        if (left == -1) return -1;
        int right = getHight(root->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
    // 判断树是否平衡
    bool isBalanced(TreeNode* root) {
        return getHight(root) == -1 ? false : true;
    }
};
// @lc code=end

