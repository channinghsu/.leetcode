/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

 // @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // for (int i = 1; i <= n1; i++) {
        //     for (int j = 1; j <= n2; j++) {
        //         if (s[i - 1] == t[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         } else {
        //             dp[i][j] = dp[i][j - 1];
        //         }
        //     }
        // }
        // return dp[n1][n2] == s.size();
        int j = 0;
        for (int i = 0; i < n2; i++) {
            if (j < n1 && s[j] == t[i]) {
                j++;
            }
        }
        return j == n1;
    }
};
// @lc code=end

