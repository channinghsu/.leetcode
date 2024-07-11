/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int> &nums) {
    // 可以到达最远的位置
    int fastest = 0;

    int cur = 0;
    int res = 0;

    // 只需要走到数组倒数第二位，因为本题就是判断是否可以走到最后一位
    for (int i = 0; i < nums.size() - 1; i++) {
      // 可以到达最远的位置
      fastest = max(fastest, i + nums[i]);
      // 判断当前是否已经到达最远的位置
      if (i == cur) {
        // 如果是那么就记录这一跳
        res++;
        // 最远的距离给 cur，再去看下一个 i能否走到这个最远的位置
        cur = fastest;
        if (cur >= nums.size() - 1) return res;
      }
    }
    return res;
  }
};
// @lc code=end
