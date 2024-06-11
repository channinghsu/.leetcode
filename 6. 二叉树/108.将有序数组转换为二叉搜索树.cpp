/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
   private:
    // 左闭右闭区间[left, right]
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        // 递归终止条件
        if (left > right) return nullptr;
        // 找到中间节点
        int mid = left + ((right - left) / 2);
        // 将中间节点设为根节点
        TreeNode* root = new TreeNode(nums[mid]);
        // 递归构造左右子树
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }

   public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
