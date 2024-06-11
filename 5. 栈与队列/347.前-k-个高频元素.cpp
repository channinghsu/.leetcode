/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
  public:
    class mycomparison { // 小顶堆
      public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        // 用固定大小为k的小顶堆，扫描所有概率的数值
        for (auto& [val, feq] : map) {
            pri_que.emplace(val, feq); // 键值对
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        // 找出前k个高频元素，因为小顶堆所以先弹出最小的，倒序输出到res
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};
// @lc code=end
