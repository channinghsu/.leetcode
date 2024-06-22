/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
    Node *connect(Node *root) {
        queue<Node *> que;
        if (root != nullptr) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node *cur = que.front();
                que.pop();
                // 若每层遍历到最后一个元素时使其next指向NULL，否则指向当前层的下一个元素
                if (i < size - 1) cur->next = que.front(); // 下一个元素是弹出后的队头元素
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return root; // 直接返回root
    }
};
// @lc code=end
