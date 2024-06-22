/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root !=nullptr) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* pre = nullptr;
            for (int i = 0; i < size; ++i) {
                Node* cur = q.front();
                q.pop();
                if (pre != nullptr) pre->next = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                pre = cur;
            }
        }
        return root;
    }
};
// @lc code=end
