/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        unordered_map<int,int> map;
        vector<int> res(n,0);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int t = s.top(); s.pop();
                res[t] = i - t;
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

