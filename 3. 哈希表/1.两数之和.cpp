/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       // 使用哈希表来存储每个数字及其索引
       unordered_map<int, int> res;
       for (int i = 0; i < nums.size(); i++) {
           int complement = target - nums[i];
           // 如果目标补数在哈希表中，返回其索引和当前索引
           if (res.count(complement)) {
                return {res[complement], i};
           }
           // 否则，将当前数字及其索引存入哈希表
            res[nums[i]] = i;
        }
       // 如果没有找到匹配的数字对，返回空数组
       return {};
    }
};
// @lc code=end

