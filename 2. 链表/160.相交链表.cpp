/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * curA = headA;
        ListNode * curB = headB;
        int sizeA = 0, sizeB = 0;

        // 计算listA的长度
        while(curA != NULL) {// 别他妈简写了 大括号都给我加上
            curA = curA->next; 
            sizeA++;
            } 
        // 计算listB的长度
        while(curB != NULL) {
            curB = curB->next; 
            sizeB++;
            }

        // 让A成为最长的链表
        if (sizeA < sizeB){
            swap(headA, headB);
            swap(sizeA, sizeB);
        }
        int n = sizeA - sizeB; // 计算出两个链表的差值

        curA = headA;
        curB = headB;

        // 是两个链表尾部对齐（将curA指向第n个元素）
        while(n--){
            curA = curA->next;
        }

        // 依次判断链表元素是否相等
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
// @lc code=end

