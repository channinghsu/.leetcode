/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

 // @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> s;
        vector<int> res;
        unordered_map<int,int> map;

        for (int i = 0; i < n2; i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                map[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < n1; i++) {
            if (map.find(nums1[i]) != map.end()) {
                res.push_back(map[nums1[i]]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end

