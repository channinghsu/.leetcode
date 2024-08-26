/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        q.push(x);
    }
    // 把队列元素取出，再加入队列里
    int pop() {
        int size = q.size() - 1;
        while (size--) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

