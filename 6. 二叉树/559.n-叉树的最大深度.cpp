/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        int depth = 0;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* cur = que.front();
                que.pop();
                for (auto child : cur->children) {
                    if(child) que.push(child);
                }
            }
        }
        // if(root == nullptr) return 0;
        // int depth = 0;
        // for (Node* child : root->children) {
        //     depth = max(maxDepth(child), depth); 
        // }
        // return depth + 1;
        return depth;
    }
};
// @lc code=end

