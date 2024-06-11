/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()){
            int size = que.size();
            double vals = 0; // 二叉树一层值的和
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                vals += cur->val;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(vals/size); // 平均值
        }
        return res;
    }
};
// @lc code=end

