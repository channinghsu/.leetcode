/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++){
            // if (nums[i] > target) return res; 错误剪枝，因为值是任意值
            if (nums[i] > target && nums[i] >= 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int k = i + 1; k < nums.size(); k++){
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }
                int left = k + 1;
                int right = nums.size() - 1;
                if (k > i + 1 && nums[k] == nums[k - 1]) continue; // k > i+ 1
                while (left < right) {
                    long sum = (long)nums[i] + nums[k] + nums[left] + nums[right]; // 数值太大超过int了
                    if (sum < target) left++;
                    else if (sum > target) right--;
                    else {
                        res.push_back(vector<int>{nums[i], nums[k], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
                                    
            }
        }
        return res;
    }
};
// @lc code=end

