/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            // 若出现符号，则计算并加入栈
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                // 得到栈顶的前两个元素
                long long num1 = stk.top();
                stk.pop();
                long long num2 = stk.top();
                stk.pop();
                if (s == "+") stk.push(num2 + num1);
                else if (s == "-") stk.push(num2 - num1);
                else if (s == "*") stk.push(num2 * num1);
                else if (s == "/") stk.push(num2 / num1);
            } else {
                stk.push(stoll(s)); // string to long long 
            }
        }
        return stk.top();
    }
};
// @lc code=end

