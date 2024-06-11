/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;   // 创建一个队列用于层序遍历
        if (root != nullptr) que.push(root); // 将根节点入队
        vector<vector<int>> res; // 存储层序遍历结果的二维向量

        while (!que.empty()) {
            int size = que.size(); // 当前层的节点个数
            vector<int> vec;       // 存储当前层节点值的向量

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front(); // 从队列中取出一个节点
                que.pop();                    // 出队

                vec.push_back(node->val);     // 将节点值添加到当前层的向量中

                if (node->left) que.push(node->left);   // 如果左子节点存在，将左子节点入队
                if (node->right) que.push(node->right); // 如果右子节点存在，将右子节点入队
            }

            res.push_back(vec); // 将当前层的向量添加到结果二维向量中
        }

        return res; // 返回层序遍历的结果
    } right
};

// @lc code=end
