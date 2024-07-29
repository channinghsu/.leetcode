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
        // dp[i][j] A[i]  结尾和 B[j]结尾 的数组的最长重复子数组
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        dp[0][0] = 0;
        int res = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];

    }
};
// @lc code=end

