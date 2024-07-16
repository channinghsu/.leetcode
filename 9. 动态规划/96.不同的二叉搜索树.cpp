/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // 逐一计算从 1 到 n 节点数目时的 dp[i]
    for (int i = 1; i <= n; i++) {
    // 遍历每个可能的根节点 j，并根据递推公式更新 dp[i]。
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
// @lc code=end
