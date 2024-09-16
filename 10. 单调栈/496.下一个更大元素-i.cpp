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

        unordered_map<int, int> map;
        for (int i = 0; i < n1; i++) {
            map[nums1[i]] = i;
        }

        stack<int> s;
        vector<int> res(n1, -1);
        for (int i = 0; i < n2; i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                if (map.find(nums2[s.top()]) != map.end()) {
                    res[map[nums2[s.top()]]] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
