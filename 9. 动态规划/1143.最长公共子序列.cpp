/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

 // @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        int n1 = A.size();
        int n2 = B.size();
        // dp[i][j] : A 字符串以i-1结尾，B 字符串以 j-i 结尾的最长公共子序列
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        int res = 0;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {

                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
};
// @lc code=end

