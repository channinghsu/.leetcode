/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
  public:
    stack<int> stkIn, stkOut;

    MyQueue() {}

    void push(int x) {
        stkIn.push(x);
    }

    int pop() {
        // 出栈时，把stkIn所有元素加入到Out中，然后再出栈
        if (stkOut.empty()) {
            while (!stkIn.empty()) {
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
        }
        int res = stkOut.top();
        stkOut.pop();
        return res;
    }

    // int peek() {
    //     // int res = this->pop();
    //     // stkOut.push(res);
    //     return res;
    // }

    int peek() {
        int res = this->pop();
        stkOut.push(res);
        return res;
    }

    bool empty() {
        return stkIn.empty() && stkOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
