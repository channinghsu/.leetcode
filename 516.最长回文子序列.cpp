/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

 // @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[i]：前 i 个字符的最长回文子序列
        vector<int> dp(n, 0);
        dp[0] = 1;

        int res = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = isHui(s, i) ? dp[i - 1] + 1 : dp[i - 1];
            res = max(res, dp[i]);
        }
        return res;
    }

    bool isHui(string& s, int end) {
        int start = 0;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end

