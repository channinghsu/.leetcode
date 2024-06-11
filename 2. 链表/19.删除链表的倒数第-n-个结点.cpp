/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // 虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 双指针指向虚拟头结点
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;

        n = n + 1;
        // 将快指针向后移动n+1个位置，为了让fast与slow之间隔着n个节点
        while (n--) 
        {
            fast = fast->next;
        }

        // 同时移动双指针
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // 删除slow后面的节点
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
// @lc code=end

