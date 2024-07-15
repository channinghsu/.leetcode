/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

    while (k--) {
      int minElement = minHeap.top();
      minHeap.pop();
      minElement = -minElement;
      minHeap.push(minElement);
    }

    int res = 0;
    while (!minHeap.empty()) {
      res += minHeap.top();
      minHeap.pop();
    }
    return res;
  }
};
// @lc code=end
