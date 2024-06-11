/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        // 库函数 reverse
        // reverse(s.begin(), s.end());
        // 双指针
        // 若为一个字符，直接返回
        if (s.size() == 1) return;
        // 定义快慢指针
        int slow = 0;
        int fast = s.size() - 1;
        // 首尾交换
        while ( slow < fast) {
            swap(s[slow], s[fast]);
            slow++;
            fast--;
        }
    }
};
// @lc code=end

