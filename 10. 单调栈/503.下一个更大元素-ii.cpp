/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

 // @lc code=start
// 版本二
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> s;
        vector<int> res(nums.size(), -1);

        for (int i = 0; i < nums.size() * 2; i++) {
            while (!s.empty() && nums[i % nums.size()] > nums[s.top()]) {
                res[s.top()] = nums[i % nums.size()];
                s.pop();
            }
            s.push(i%nums.size());
        }
        return res;
    }
};

