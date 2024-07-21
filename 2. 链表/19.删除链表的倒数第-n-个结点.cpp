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
      // 找到倒数第 n 个节点的前一个节点
      ListNode* dummyNode = new ListNode(0);
      dummyNode->next = head;
      ListNode* fast = dummyNode;
      ListNode* cur = dummyNode;

      // 移动 fast 节点，使 fast 和 slow 差 n+1
      n += 1;
      while (n--) {
        fast = fast->next;
      }

      // 移动fast，使 fast 到链表的最后
      while (fast != nullptr) {
          fast = fast->next;
          cur = cur->next;
      }

      // 删除 cur->next
      ListNode* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;

      return dummyNode->next;
    }
};
// @lc code=end
