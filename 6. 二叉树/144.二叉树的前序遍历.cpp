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
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;               // 用于存储前序遍历结果
    stack<TreeNode*> st;           // 栈用于迭代遍历二叉树

    if (root == nullptr) return res; // 如果根节点为空，返回空结果

    st.push(root);                  // 将根节点压入栈中

    while (!st.empty()) {           // 当栈不为空时，进行循环
        TreeNode* node = st.top();  // 取出栈顶节点
        st.pop();                   // 弹出栈顶节点
        res.push_back(node->val);   // 将节点值加入结果数组

        if (node->right) st.push(node->right); // 先将右子节点压入栈中
        if (node->left) st.push(node->left);   // 再将左子节点压入栈中
    }

    return res;                     // 返回前序遍历结果
}
;
// @lc code=end

