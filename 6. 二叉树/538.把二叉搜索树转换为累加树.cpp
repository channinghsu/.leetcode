/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int pre = 0;
    void dfs(TreeNode* cur) {
        // 深度优先搜索（DFS）：dfs 函数用于遍历树，采用右-根-左的顺序，这样可以确保在遍历每个节点时已经累加了所有比它大的节点值。
        if (cur == nullptr) return;
        dfs(cur->right);
        cur->val += pre;
        pre = cur->val;
        dfs(cur->left);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
// @lc code=end
