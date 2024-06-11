/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
  public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (char c : s) {∑
            // 若栈不为空，并且栈顶元素和将要进来的元素相等时，直接弹出
            if (!stk.empty() && c == stk.top()) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();  // 记得要弹出已经添加的元素
        }
        reverse(res.begin(), res.end()); // 最后反转字符串
        return res;
    }
};
// @lc code=end
