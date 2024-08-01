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
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);

        for (int i = 0; i < n * 2; i++) {
            int num = i % n;
            while (!s.empty() && nums[num] > nums[s.top()]) {
                res[s.top()] = nums[num];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};
