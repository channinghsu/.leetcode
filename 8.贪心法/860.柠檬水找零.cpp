/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int b : bills) {
            if (b == 5) {
                five++;
            } else if (b == 10) {
                five--;
                if (five < 0) return false;
                ten++;
            } else {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                } else if (five >=3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

