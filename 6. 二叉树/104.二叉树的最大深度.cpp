/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
     int maxDepth(TreeNode* root) {
        // int res = 0;
        // queue<TreeNode*> que;
        // if (root != nullptr) que.push(root);
        // while (!que.empty()) {
        //     int size = que.size();
        //     for (int i = 0; i < size; ++i) {
        //         TreeNode* cur = que.front();
        //         que.pop();
        //         if (cur->left) que.push(cur->left);
        //         if (cur->right) que.push(cur->right);
        //     }
        //     res++;
        // }
        // return res;
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// @lc code=end

