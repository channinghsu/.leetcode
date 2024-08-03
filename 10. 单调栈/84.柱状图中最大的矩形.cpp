/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

 // @lc code=start
 // 版本二
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);
        int n = heights.size();

        int res = 0;
        for (int i = 1; i < n; i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int h = heights[mid];
                int w = i - st.top() - 1;
                res = max(res,h*w);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

