/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = __INT32_MAX__; //  长度最小子数组
        int i = 0; // 滑动窗口起始位置
        int sum = 0; // 滑动窗口数值之和
        for (int j = 0; j < nums.size(); j++){
            sum += nums[j]; 
            while(sum >= target){
                result = min(result, j - i + 1);
                sum -= nums[i++];
            }
        }
        return result == __INT32_MAX__ ? 0 : result;
    }
};
// @lc code=end

