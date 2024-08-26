/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

 // @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size()% 2 != 0) return false;
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        if (!st.empty()) return false;
        return true;
    }
};
// @lc code=end

