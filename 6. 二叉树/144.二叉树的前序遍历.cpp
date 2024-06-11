/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // void preOrder(TreeNode* cur, vector<int>& vec){
    //     if (cur == nullptr) return;
    //     vec.push_back(cur->val);
    //     preOrder(cur->left, vec);
    //     preOrder(cur->right, vec);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // preOrder(root, vec);
        // return res;
        stack<TreeNode*> st;
        if (root == nullptr) return res;
        st.push(root);   
        while (!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }
};
// @lc code=end

