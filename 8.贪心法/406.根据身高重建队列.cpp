/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // 贪心法：有两边，先考虑一边
    // 先按身高降序，然后再按照 k 排序，k 是几就放到第几个
    // 因为现放的肯定比后放的身高高，假如当前要放(5, 2)
    // 前面放的都是比 5 高的人，所以从前往后数放到第二个准没错

    // 重载 cmp 函数，按身高降序, 若身高相同，按 k 升序
    sort(people.begin(), people.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
         });

    // 按照 k的大小,插入
    list<vector<int>> list;
    for (auto& p : people) {
      // std::list<vector<int>>::iterator it = list.begin();
      auto it = list.begin();
      //
      advance(it, p[1]);
      list.insert(it, p);
    }
    return vector<vector<int>>(list.begin(), list.end());
  }
};
// @lc code=end
