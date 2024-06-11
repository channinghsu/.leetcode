/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postOrder(TreeNode* cur, vector<int>& vec){
        if ( cur == nullptr) return;
        postOrder(cur->left, vec);
        postOrder(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};
// @lc code=end

