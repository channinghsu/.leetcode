/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

 // @lc code=start
class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int n = s.size();

        // 遍历每个 2k 块
        for (int i = 0; i < n; i += 2 * k) {
            // 计算当前块的结束位置，避免越界
            int end = std::min(i + k, n);
            // 使用 STL 库的 reverse 函数反转当前块
            std::reverse(s.begin() + i, s.begin() + end);
        }

        return s;
    }
};

// @lc code=end
