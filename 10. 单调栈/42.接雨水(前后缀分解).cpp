/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

 // @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 每一块的水的体积 = min(left, right) - cur;

        int n = height.size();
        vector<int> left;
        vector<int> right;
        int leftMax = 0;
        int rightMax = 0;

        vector<int> pre_max(n); // pre_max[i] 表示从 height[1] 到 height[i] 的最大值

        pre_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i - 1], height[i]);
        }

        vector<int> suf_max(n); // suf_max[i] 表示从 height[i] 到 height[n-1] 的最大值
        suf_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_max[i] = max(suf_max[i + 1], height[i]);
        }

       int res = 0;
       for (int i = 1; i < n - 1; i++) {
           res += min(pre_max[i],suf_max[i]) - height[i];
        }
       return res;
    }
};
// @lc code=end

