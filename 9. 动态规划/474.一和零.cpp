/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // 01背包问题: 背包内放 item，总价值最高，背包有最大容量，每个物品有 value
    // 和 weight 本题：背包内放数组，含 1,0 最多，背包里最多m 个 0，n 个
    //
    // 1，每个数组有自己的 0和 1
    // dp 数组表示：最多有 i 个 0，j 个 1 是最大的子集的个数。
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // 先遍历item
    for (string s : strs) {
      int zeroNum = 0;
      int oneNum = 0;

      for (char c : s) {
        if (c == '0') zeroNum++;
        else oneNum++;
      }

      for (int i = m; i >= zeroNum; i--) {
        for (int j = n; j >= oneNum; j--) {
          dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
