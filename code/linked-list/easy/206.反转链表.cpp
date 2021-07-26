/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.00%)
 * Likes:    1860
 * Dislikes: 0
 * Total Accepted:    619.3K
 * Total Submissions: 859.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
 * 
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
    // 迭代
    // 63.03%/96.93%
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        auto a=head, b=a->next;
        while(b) {
            auto temp = b->next;
            // 反转指针
            b->next = a;
            // 后移指针
            a = b;
            b = temp;
        }
        head->next=nullptr;
        return a;
    }

    // 递归
    // 100%/19.61%
    // ListNode* reverseList(ListNode* head) {
    //     if(!head||!head->next) return head;
    //     // 反转head->next之后的指针
    //     auto tail = reverseList(head->next);
    //     // 反转head->next对应的指针
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return tail;
    // }
};
// @lc code=end

