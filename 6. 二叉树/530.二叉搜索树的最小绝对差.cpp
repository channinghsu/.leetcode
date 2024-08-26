class Solution {
public:
    // 深度优先搜索（中序遍历），寻找最小绝对差
    void dfs(TreeNode* cur, TreeNode*& pre, int& res) {
        if (cur == nullptr) return;
        // 递归遍历左子树
        dfs(cur->left, pre, res);
        // 更新最小绝对差
        if (pre != nullptr) {
            res = min(res, cur->val - pre->val);
        }
        // 更新前驱节点
        pre = cur;
        // 递归遍历右子树
        dfs(cur->right, pre, res);
    }

    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* pre = nullptr;
        dfs(root, pre, res);
        return res;
    }
};