/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

 // @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i : nums) {
            map[i]++;
        }

        // 小顶堆，按照频率排序
        auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
            };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);


        for (auto& m : map) {
            minHeap.emplace(m.first, m.second);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        // 逆序结果以保证顺序
        reverse(res.begin(), res.end());
        return res;
    }
};