/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n, vector<int>(n, 0));
        int left = 0, top = 0, right = n - 1, bottom = n - 1;
        int num = 1;
        while (num <= n * n){ // num 写成 n 
            for (int i = left; i <= right; i++) res[top][i] = num++;
            top++;
            
            for (int i = top; i <= bottom; i++) res[i][right] = num++;
            right--;

            for (int i = right; i >= left; i--) res[bottom][i] = num++;
            bottom--;
            
            for (int i = bottom; i >= top; i--) res[i][left] = num++;
            left++;
        }
        return res; // 别忘了返回值
    }
};
// @lc code=end

