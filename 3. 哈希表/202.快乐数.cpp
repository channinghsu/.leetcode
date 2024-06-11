/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
  public:
    // 计算n各位的平方和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        // 用一个set记录平方和
        unordered_set<int> set;

        while (1) {
            int sum = getSum(n);
            // 是快乐数
            if (sum == 1) return true;
            // 若集合中存在sum，不是快乐数
            if (set.count(sum)) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum; // 别忘了
        }
    }
};
// @lc code=end
