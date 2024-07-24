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
        while(n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
      }
    bool isHappy(int n) {
        // 用一个set记录平方和
        unordered_set<int> set;
        int pre = 0;
        while(true) {
            int num = getSum(n);
            if (num == 1) return true;
            if (set.find(num) != set.end()) return false;
            else set.insert(num);
            n = num;
        }
    }
};

// @lc code=end
