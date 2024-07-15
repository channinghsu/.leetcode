/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int pre = 0;
    int res = 1;
    for (int i = 1; i < nums.size(); ++i) {
        int cur = nums[i] - nums[i-1];
        if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0)) {
            res++;
            pre = cur;
        }
    }
    return res;
  }
};
// @lc code=end
