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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lengthA = 0;
    int lengthB = 0;
    while (curA != nullptr) {
      lengthA++;
      curA = curA->next;
    }

    while (curB != nullptr) {
      lengthB++;
      curB = curB->next;
    }

    curA = headA;
    curB = headB;

    int num = 0;
    ListNode* tmp = nullptr;
    if (lengthB > lengthA) {
        swap(curA,curB);
        swap(lengthA,lengthB);
    }
    num = lengthA - lengthB;

    while (num--) {
      curA = curA->next;
    }

    while (curA != nullptr) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return nullptr;
  }
};
// @lc code=end
