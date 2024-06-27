/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int count = 0;
    int maxCount = 0;
    vector<int> res;
    TreeNode* pre = nullptr;
    void dfs(TreeNode* cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }
        pre = cur;
        if (count == maxCount) {
            res.push_back(cur->val);
        } else if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(cur->val);
        }

        dfs(cur->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end
