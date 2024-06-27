/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* dfs(vector<int>&nums, int left, int right) {
        if (left >= right) return nullptr;
        int max = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > nums[max]) max = i;
        }
        TreeNode* node = new TreeNode(nums[max]);
        node->left = dfs(nums,left,max);
        node->right = dfs(nums,max + 1,right);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};
// @lc code=end

