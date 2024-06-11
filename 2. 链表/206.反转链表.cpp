/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head; // 当前节点
        ListNode* pre = NULL; // 前一个节点
        while(cur){ // 当前节点不为空
            temp = cur->next; 
            cur->next = pre; // 凡转
            pre = cur; // pre向前移
            cur = temp; // cur向前移
        }
        return pre;
    }
};
// @lc code=end

