/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    // 问题转化：选择石头，他们的和为sum/2,这样 最后剩下的一 块才最小
    int sum = accumulate(stones.begin(), stones.end(),0);
    int target = sum / 2;
    vector<int> dp(target + 1, 0);

    for (int stone : stones) {
      for (int i = target; i >= stone; i--) {
        dp[i] = max(dp[i], dp[i - stone] + stone);
      }
    }
    return sum - 2 * dp[target];
  }
};
// @lc code=end
