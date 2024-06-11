/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* cur, string path, vector<string>& res) {
        path += to_string(cur->val); // 中
        if (cur->left == nullptr && cur->right == nullptr) {  // 遇到叶子结点
            res.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->" , res); // 左
        if (cur->right) traversal(cur->right, path + "->", res); // 右
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        traversal(root, "", res);
        return res;
    }
};
// @lc code=end
