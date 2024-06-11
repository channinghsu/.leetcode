/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        // queue<TreeNode*> que;
        // int res = 0;
        // if (root != nullptr) que.push(root);
        // while (!que.empty()){
        //     int size = que.size();
        //     for (int i = 0; i < size; i++) {
        //         TreeNode* cur = que.front();
        //         res++;
        //         que.pop();
        //         if (cur->left) que.push(cur->left);
        //         if (cur->right) que.push(cur->right);
        //     }
        // }
        // return res;
        if (root == nullptr) return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
};
// @lc code=end
