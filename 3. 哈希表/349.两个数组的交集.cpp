/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // 使用unordered_set，存放nums1，然后在去那nums2中的数找，若有添加到res中
        // 存放nums1并去重
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            // 若nums1中存在nums2的元素，则为交集
            // if (set.find(nums2[i]) != set.end()){
            if (set.count(nums2[i])) {
                res.insert(nums2[i]);
            }
        }
        vector<int> result(res.begin(), res.end());
        return result;
    }
};
// @lc code=end
