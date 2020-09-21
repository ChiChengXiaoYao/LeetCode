/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.18%)
 * Likes:    4926
 * Dislikes: 0
 * Total Accepted:    555.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 先判断各种特殊情况
        if (l1 == nullptr)  return l2;
        if (l2 == nullptr)  return l1;

        // 链表用循环写需要处理头结点，用递归会方便很多
        int temp = l1->val + l2->val;
        ListNode* p = new ListNode(temp%10);
        p->next = addTwoNumbers(l1->next, l2->next);
        if (temp/10)
            p->next = addTwoNumbers(p->next, new ListNode(1));
        // 坏处就是内存占用爆炸
        return p;
    }
};
// @lc code=end

