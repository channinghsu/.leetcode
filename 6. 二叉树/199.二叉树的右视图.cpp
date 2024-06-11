/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != nullptr) que.push(root);
        vector<int> vec;
        while (!que.empty()) {
            // 添加每一个队列的最后一个元素到结果中
            vec.push_back(que.back()->val);
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return vec;
    }
};
// @lc code=end
