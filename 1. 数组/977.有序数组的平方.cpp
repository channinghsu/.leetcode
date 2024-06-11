/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        int k = j;
        vector<int> result(A.size(), 0);
        while (i <= j)
        {
            if(A[i] * A[i] > A[j] * A[j]){
                result[k--] = A[i] * A[i];
                i++;
            } else {
                result[k--] = A[j] * A[j];
                j--;
            }
        }
        return result;
    }
};
// @lc code=end

