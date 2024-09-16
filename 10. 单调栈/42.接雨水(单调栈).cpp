/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

 // @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        s.push(0);
        int res = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int mid = s.top();
                s.pop();
                if (s.empty()) break;
                int w = i - s.top() - 1;
                int h = min(height[i], height[s.top()]) - height[mid];
                res += w * h;
            }
                s.push(i);
            }
            return res;
        }

    };
    // @lc code=end

