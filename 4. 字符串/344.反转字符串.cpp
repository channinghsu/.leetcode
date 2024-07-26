/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

 // @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n / 2; i++) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

