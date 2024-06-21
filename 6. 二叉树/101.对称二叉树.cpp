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
};
// @lc code=end
