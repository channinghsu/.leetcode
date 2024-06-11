/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
    class Solution {
    public:
        bool isValid(string s) {
            // if (s.size() % 2 != 0) return false; // 如果s的长度围奇数，一定不符合条件
            stack<char> stk;
            for (char c : s) {
                if (c == '{') stk.push('}');
                else if (c == '[') stk.push(']');
                else if (c == '(') stk.push(')');
                // 匹配的过程中发现栈空了或者和左边不匹配
                else if (stk.empty() || stk.top() != c) return false;
                else stk.pop();
            }
            // 若最后栈内有剩余元素
            return stk.empty();
        }
    };
// @lc code=end

