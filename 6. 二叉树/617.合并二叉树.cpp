/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
class solution {
public:
    treenode* mergetrees(treenode* root1, treenode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        // 前序遍历
        treenode* node = new treenode(0);
        node->val = root1->val + root2->val;
        node->left = mergetrees(root1->left,root2->left);
        node->right = mergetrees(root1->right,root2->right);
        return node;
   }
};
// @lc code=end

