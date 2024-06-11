/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
        bool isSymmetric(TreeNode* root) {
            return root == nullptr || recur(root->left, root->right);
        }
    private:
        bool recur(TreeNode* L, TreeNode* R){
            if (L == nullptr && R == nullptr) return true;
            if (L == nullptr || R == nullptr || L->val != R->val) return false;
            return recur(L->left, R->right) && recur(L->right, R->left);
        }

        // 递归第一步，先确定参数及返回值
        bool compare(TreeNode* left, TreeNode* right) {
            // 递归第二步，写出终止条件
            if (right && left == nullptr) return false;
            else if (right == nullptr && left) return false;
            else if (right == nullptr && left == nullptr) return true;
            else if (right->val != left->val) return false;
            // 递归第三步，确定单层递归的逻辑
            bool outside = compare(left->left, right->right);
            bool inside = compare(left->right, right->left);
            bool res = outside && inside;
            return res;
        }
};
// @lc code=end
