/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

class Solution {
  public:
    class MonotonicQueue { // 单调队列（从大到小）
      private:
        deque<int> que; // 用deque实现单调队列
      public:
        // 每次弹出时，弹出max
        void pop(int n) {
            if (n == que.front()) {
                que.pop_front();
            }
        }
        // 入队时，”压扁“前面所有小于当前入队的数值，保持队列单调递减
        void push(int n) {
            while (!que.empty() && que.back() < n) {
                que.pop_back();
            }
            que.push_back(n);
        }
        // 查询当前队列里的最大值，也就是最前端的元素
        int front() {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                // 先将前k个元素入队
                window.push(nums[i]);
            } else {
                // 滑动窗口前加入最后面的元素
                window.push(nums[i]);
                // 当前窗口的最大值
                res.push_back(window.front());
                // 滑动窗口移除最前面（大）元素
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end
