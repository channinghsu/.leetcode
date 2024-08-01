/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

 // @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            res = max(min(height[left], height[right]) * (right - left), res);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

