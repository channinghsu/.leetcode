/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

 // @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) { // 注意这里是while
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1; // 注意减一，只求中间宽度
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
};
// @lc code=end

