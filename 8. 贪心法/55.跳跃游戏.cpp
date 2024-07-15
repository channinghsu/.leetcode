/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0; // 能到达的最远位置
        if (nums.size() == 1) return true;
        for (int i = 0; i < nums.size(); ++i) {
            // 更新能到达的最远位置
            farthest = max(farthest, i + nums[i]);
            // 如果能到达或超过最后一个位置，返回 true
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return false;
    }
};;
// @lc code=end

