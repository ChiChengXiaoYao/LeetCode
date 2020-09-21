/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 先判断各种特殊情况
        if (l1 == nullptr)  return l2;
        if (l2 == nullptr)  return l1;

        // 链表用循环写需要处理头结点，用递归会方便很多
        int temp = l1->val + l2->val;
        ListNode* p = new ListNode(temp%10);
        p->next = addTwoNumbers(l1->next, l2->next);
        if (temp/10)
            p->next = addTwoNumbers(p->next, new ListNode(1));
        return p;
    }
};
// @lc code=end
