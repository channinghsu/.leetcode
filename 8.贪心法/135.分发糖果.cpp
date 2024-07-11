/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        vector<int> score(n, 1);
        // 从左到右遍历，确保每个孩子比右边评分高的孩子糖果多
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                score[i] = score[i - 1] + 1;
            }
        }
        // 从右到左遍历，确保每个孩子比左边评分高的孩子糖果多
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                // 取孩子 i 当前的糖果数和孩子 i+1 糖果数加一的较大值，确保孩子 i 得到的糖果数不少于 score[i + 1] + 1。
                score[i] = max(score[i], score[i + 1] + 1);
            }
        }
        // 计算总糖果数
        int res = 0;
        for (int candy : score) {
            res += candy;
        }

        return res;
    }
};
// @lc code=end
