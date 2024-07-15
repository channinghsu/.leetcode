/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;   // 当前油量的累计和
        int totalSum = 0; // 总油量和总消耗的差值累计
        int start = 0;    // 起始加油站的索引

        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];  // 计算当前加油站的油量变化
            totalSum += gas[i] - cost[i]; // 计算总的油量变化

            // 如果当前油量小于0，更新起点
            if (curSum < 0) {
                start = i + 1;  // 更新起点为下一个加油站
                curSum = 0;     // 重置当前油量
            }
        }

        // 检查总油量是否足够绕一圈
        if (totalSum < 0) return -1; // 总油量小于总消耗，不可能绕一圈
        return start; // 返回起点
    }
};;
// @lc code=end

