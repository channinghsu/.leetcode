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
    // 层序遍历二叉树，返回每一层的节点值
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; // 存储结果的二维数组
        if (!root) return res; // 如果根节点为空，直接返回空结果
        queue<TreeNode*> q; // 使用队列进行层序遍历
        q.push(root); // 将根节点入队

        while (!q.empty()) { // 当队列不为空时，继续遍历
            int size = q.size(); // 当前层的节点数
            vector<int> row; // 存储当前层的节点值
            for (int i = 0; i < size; i++) { // 遍历当前层的所有节点
                TreeNode* node = q.front(); // 取出队首节点
                q.pop(); // 将队首节点出队
                row.push_back(node->val); // 将节点值存入当前层的数组
                if (node->left) q.push(node->left); // 如果左子节点存在，将其入队
                if (node->right) q.push(node->right); // 如果右子节点存在，将其入队
            }
            res.push_back(row); // 将当前层的节点值数组存入结果数组
        }
        return res; // 返回结果数组
    }
};

// @lc code=end
