/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (52.11%)
 * Likes:    826
 * Dislikes: 0
 * Total Accepted:    143.9K
 * Total Submissions: 266.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 头指针可能会变，也可能不变，创建一个虚拟节点指向头指针进行统一操作(即头结点)
        auto dummy = new ListNode(-1);
        dummy->next = head;
        // 找到要反转的节点的前一个节点(这个节点的指针也需要修改)
        auto a = dummy;
        for(int i = 0; i < left-1; ++i)
            a = a->next;
        // 正常反转链表的思路,b、c两个工作指针，d用于备份下一个位置
        auto b = a->next, c = b->next;
        for(int i = left; i < right; ++i){
            auto d = c->next;
            c->next = b;
            b = c, c = d;
        }
        // 处理反转链表前后的两个指针
        a->next->next = c;
        a->next = b;
        // 返回头结点的下一个
        return dummy->next;
    }
};
// @lc code=end

